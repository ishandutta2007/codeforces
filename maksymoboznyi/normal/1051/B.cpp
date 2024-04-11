#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

signed main()
{
    int l, r;
    cin >> l >> r;
    cout << "YES\n";
    for (int i = l; i <= r; i += 2)
        cout << i << ' ' << i+1 << "\n";
    return 0;
}