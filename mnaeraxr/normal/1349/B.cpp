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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int j = 0;
    while (j < n && a[j] != k)
        ++j;

    if (j == n)
    {
        cout << "no" << endl;
        return;
    }

    if (n == 1)
    {
        cout << "yes" << endl;
        return;
    }

    int best = 1;
    int acc = 0;

    for (auto x : a)
    {
        int v = x >= k ? +1 : -1;

        int cur = acc + v;

        if (cur > best)
        {
            cout << "yes" << endl;
            return;
        }

        best = min(best, acc);
        acc = cur;
    }

    cout << "no" << endl;
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