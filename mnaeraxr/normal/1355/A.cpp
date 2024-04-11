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

#define endl '\n'

using namespace std;

pair<int, int> minmax(long long a)
{
    int m = 10, M = 0;

    while (a)
    {
        int d = a % 10;
        m = min(m, d);
        M = max(M, d);
        a /= 10;
    }

    return {m, M};
}

void solve()
{
    long long a, k;
    cin >> a >> k;

    k--;

    while (k--)
    {
        auto p = minmax(a);
        if (p.first != 0)
            a += p.first * p.second;
        else
            break;
    }

    cout << a << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}