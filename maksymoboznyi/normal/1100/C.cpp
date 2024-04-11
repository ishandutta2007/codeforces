#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

int n, m, a[N], kol[N], sum = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    double r;
    cin >> n >> r;
    double ang = acos(-1)*2 / n;
    double ang2 = acos(-1) - ang;
    ang2 /= 2;
    ang = sin(ang);
    ang2 = sin(ang2);
    cout << fixed << setprecision(7) << r * ang / (2 * ang2 - ang);
    return 0;
}