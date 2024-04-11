#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const long long hidden = 975265380;

long long _gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return _gcd(b, a % b);
}

long long get(long long q)
{
    // return _gcd(q, hidden);
    cout << "? " << q << endl;
    cout.flush();

    long long gcd;
    cin >> gcd;
    return gcd;
}

vector<long long> primes;
vector<vector<long long>> pw;

const long long top = 1e18;
const long long top9 = 1e9;

void init()
{
    const int maxn = 50000;
    vector<bool> s(maxn, true);

    for (int i = 2; i < maxn; ++i)
    {
        if (!s[i])
            continue;

        primes.push_back(i);
        pw.push_back({1, i});

        while (pw.back().back() <= top9 / i)
        {
            auto nw = pw.back().back() * i;
            pw.back().push_back(nw);
        }

        for (int j = 2 * i; j < maxn; j += i)
            s[j] = false;
    }
}

void solve()
{
    int t = primes.size();
    vector<long long> lo(t), hi(t);

    for (int i = 0; i < t; ++i)
    {
        hi[i] = pw[i].size();
    }

    int q = 22, pos = 0;

    set<int> s;

    while (q--)
    {
        long long cur = 1;

        for (int i = 0; i < t; ++i)
        {
            if (lo[i] + 1 == hi[i])
                continue;

            int m = lo[i] == 0 ? 1 : hi[i] - 1;

            if (pw[i][m] <= top / cur)
            {
                cur *= pw[i][m];

                if (m)
                    s.insert(primes[i]);
            }
        }

        auto res = get(cur);

        cur = 1;

        for (int i = 0; i < t; ++i)
        {
            if (lo[i] + 1 == hi[i])
                continue;

            int m = lo[i] == 0 ? 1 : hi[i] - 1;

            if (pw[i][m] <= top / cur)
            {
                cur *= pw[i][m];

                if (res % pw[i][m] == 0)
                {
                    lo[i] = m;
                }
                else
                {
                    while (res % pw[i][lo[i]] == 0)
                    {
                        lo[i]++;
                    }
                    hi[i] = lo[i]--;
                }
            }
        }
    }

    long long res = 1;

    for (int i = 0; i < t; ++i)
    {
        res *= lo[i] + 1;

        // if (lo[i])
        // {
        //     cerr << primes[i] << " " << lo[i] << endl;
        // }
    }

    cout << "! " << max(2 * res, res + 7LL) << endl;

    // for (auto xx : s)
    //     cerr << xx << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}