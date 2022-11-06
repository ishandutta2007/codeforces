#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
#define int long long
using namespace std;

const int M = 998244353;


const int N = 1e6 + 5;
int bf[N], f[N];
int n;

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
    if (b % 2 == 0) {
        a *= a;
        a %= M;
        b /= 2;
    } else {
        res *= a;
        b--;
        res %= M;
    }
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f[0] = 1;
    bf[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % M;
        bf[i] = gp(f[i], M - 2);
    }
    int ans = f[n];
    for (int i = 1; i <= n; i++) {
        ans += f[n] * bf[n - i] % M*(f[n - i]- 1) % M;
        //cout << ans << endl;
        ans %= M;
    }
    cout << ans;
    return 0;
}