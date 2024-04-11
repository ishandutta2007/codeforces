#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

#include <experimental/optional>

#include <tuple>

namespace asl
{
    typedef long long i64;
    
} 

#include <random>

#include <utility>

#define endl '\n'

using namespace std;
using namespace asl;

i64 dc(int b, int e, string &s)
{
    if (b + 1 == e)
    {
        return s[b] == '1';
    }
    else
    {

        int m = (b + e) / 2;
        auto deep = dc(b, m, s) + dc(m, e, s);

        if (b == 0 && e == 5)
        {
            int foo = 100;
        }

        i64 cur = 0, sum_right = 0;
        map<pair<int, int>, int> freq;

        {
            bool started = true;
            int best = 0, suff = 0, pref = 0;
            for (int i = m; i < e; ++i)
            {
                if (s[i] == '1')
                {
                    suff++;
                    pref += started;
                }
                else
                {
                    started = false;
                    suff = 0;
                }
                best = max(best, suff);

                freq[{best - pref, best}]++;
                sum_right += best;
            }
        }

        auto safe_freq = freq;
        int tot_mid = 0, tot_right = (e - m), tot_left = 0;
        i64 sum_mid = 0;
        map<int, int> howmany;

        {
            bool started = true;
            int best = 0, suff = 0, pref = 0;

            for (int i = m - 1; i >= b; --i)
            {
                if (s[i] == '1')
                {
                    pref += started;
                    suff++;
                    best = max(best, suff);

                    if (started)
                    {
                        sum_mid += tot_mid;

                        while (!freq.empty() && freq.begin()->first.first <= pref)
                        {
                            int tot = freq.begin()->second;
                            int ff = freq.begin()->first.first;
                            int bb = freq.begin()->first.second;

                            sum_right -= i64(bb) * tot;
                            sum_mid += i64(bb - ff + pref) * tot;
                            tot_right -= tot;
                            tot_mid += tot;

                            freq.erase(freq.begin()->first);
                        }
                    }
                    else
                    {
                        while (!howmany.empty() && howmany.begin()->first <= best)
                        {
                            tot_left += howmany.begin()->second;
                            sum_right -= i64(howmany.begin()->second) * i64(howmany.begin()->first);
                            howmany.erase(howmany.begin()->first);
                        }
                    }
                }
                else
                {
                    if (started)
                    {
                        sum_mid = 0;
                        sum_right = 0;
                        for (auto x : safe_freq)
                        {
                            int a, b, c;
                            a = x.first.first;
                            b = x.first.second;
                            c = x.second;
                            a = b - a;
                            howmany[max(a + pref, b)] += c;
                            sum_right += i64(c) * max(a + pref, b);
                        }
                    }

                    started = false;
                    suff = 0;
                }

                cur += sum_mid + sum_right + i64(best) * tot_left;
            }
        }

        return cur + deep;
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << dc(0, n, s) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;

    for (int i = 1; i <= t; ++i)
    {
        solve();
    }

    return 0;
}