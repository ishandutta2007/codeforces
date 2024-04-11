#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 205;

int n, f[MAXN], v[MAXN], c, ma;
ll ans = 1;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a%b); }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> f[i];
    for (int i=1; i<=n; i++) {
        memset(v, 0, sizeof(v));
        c = 1;
        int cur = i;
        while (!v[cur]) {
            v[cur] = c++;
            cur = f[cur];
        }
        int x = c-v[cur];
        ans = ans/gcd(ans, x)*x;
        ma = max(ma, v[cur]-1);
    }
    cout << (max(ma-1, 0)/ans+1)*ans;
}