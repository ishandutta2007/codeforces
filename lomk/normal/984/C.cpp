#include <bits/stdc++.h>
#define int unsigned long long
#define for(i,l,r) for (int i=l;i<r;i++)
using namespace std;
int n, mod;
int mul(int a, int b) {
    int ans = 0;
    while (b) {
        if (b % 2) ans = ans + a >= mod ? ans + a - mod : ans + a;
        a = a + a >= mod ? a + a - mod : a + a;
        b /= 2;
    }
    return ans;
}
int getpow(int a, int b) {
    int ans = 1;
    while (b) {if (b % 2) ans = mul(ans, a); a = mul(a, a); b /= 2;}
    return ans;
}
signed main() {
    //freopen("984.inp","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        int p, q, b; cin >> p >> q >> b;
        q /= __gcd(p, q); mod = q;
        //Find if an x exists such that b ^ x % q == 0
        if (q == 1) {cout << "Finite\n"; continue;}
        b %= q; int cur = getpow(b, 64); bool ans = false;
        if (!cur) ans = true;
        if (ans) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}