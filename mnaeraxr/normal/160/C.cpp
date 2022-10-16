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
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    map<long long, long long> freq;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i)
    {
        long long u;
        cin >> u;
        a[i] = u;
        freq[u]++;
    }

    sort(a.begin(), a.end());

    for (auto p : freq)
    {
        if (p.second * n < k)
        {
            k -= p.second * n;
        }
        else
        {

            for (auto q : freq)
            {
                if (p.second * q.second < k)
                {
                    k -= p.second * q.second;
                }
                else
                {
                    cout << p.first << " " << q.first << endl;
                    return 0;
                }
            }
        }
    }

    assert(false);

    return 0;
}