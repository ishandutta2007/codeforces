#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>

using namespace std;

#define endl '\n'

const int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long a = 0;

    for (int i = 0; i < k; ++i)
        a += n - i;

    vector<int> p(n);

    long long b = 1;
    int last = -1;

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        if (p[i] > n - k)
        {
            if (last != -1)
            {
                b = b * (i - last) % mod;
            }
            last = i;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}