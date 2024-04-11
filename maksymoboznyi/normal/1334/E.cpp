#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int M = 998244353;

int n, q, f[N], bf[N];
vector<int> pr;

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b % 2 == 1)
            res *= a, b--, res %= M;
        else
            a *= a, b /= 2, a %= M;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
    bf[0] = 1;
    for (int i = 1; i < 200; i++)
        f[i] = f[i - 1] * i % M, bf[i] = gp(f[i], M - 2);
    cin >> n >> q;
    int p = 2, nn = n;

    while (p * p <= nn) {
        if (n % p == 0) {
            pr.pb(p);
            while (n % p == 0)
                n /= p;
        }
        p++;
    }
    if (n != 1) {
        pr.pb(n);
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        a /= g;
        b /= g;
        vector<int> q1, q2;
        int ans = 1;
        for (auto p: pr) {
            int kol = 0;
            while (a % p == 0)
                a /= p, q1.pb(p), kol++;
            while (b % p == 0)
                b /= p, q2.pb(p), kol++;
            ans *= bf[kol];
            ans %= M;
        }
        ans *= f[q1.size()];
        ans %= M;
        ans *= f[q2.size()];
        ans %= M;

        cout << ans << "\n";
    }
    return 0;
}