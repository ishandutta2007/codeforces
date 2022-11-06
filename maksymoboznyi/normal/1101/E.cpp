#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

set<int> x, y;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (a > b)
            swap(a, b);
        if (c == '+') {
            x.insert(a);
            y.insert(b);
        } else {
            auto it = x.end(), it1 = y.end();
            it--;
            it1--;
            if (*it <= a && *it1 <= b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}