#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 998244353;

bool a[N], b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    int ang;
    cin >> ang;
    int p = 180;
    int x = __gcd(p, ang);
    p /= x;
    ang /= x;
    //cout << p << ' ' << ang << endl;
    if (ang > p - 2)
        p *= 2;
    cout << p<<"\n";
    }
    return 0;
}