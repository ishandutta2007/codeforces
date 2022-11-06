#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y, b, r;
    cin >> y >> b >> r;
    int l = min(y, min(b - 1, r - 2));
    cout << 3*l + 3;
    return 0;
}