#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 200010;
const int mod = 998244353;

typedef unsigned long long ull;

int n, m;

set<int> st;
int a[maxn];
int c[maxn];
ull s[maxn], rs[maxn], pw[maxn];
ull s2[maxn], rs2[maxn], pw2[maxn];
int ans[maxn], tot = 0;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) st.insert(a[i]);
    sort(a+1, a+n+1);
    if (n == 1) {
        printf("1\n%d\n", (a[1]+a[1])%m);
        return 0;
    }
    c[1] = a[1]-a[n];
    for (int i = 2; i <= n; i++) c[i] = a[i]-a[i-1];
    for (int i = 1; i <= n; i++) {
        c[i] %= m;
        if (c[i] < 0) c[i] += m;
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i-1]*m;
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1]+ull(c[i])*pw[i];
        rs[i] = rs[i-1]+ull(c[i])*pw[n-i+1];
    }
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw2[i] = pw2[i-1]*m%mod;
    }
    for (int i = 1; i <= n; i++) {
        s2[i] = s2[i-1]+ull(c[i])*pw2[i]%mod; s2[i] %= mod;
        rs2[i] = rs2[i-1]+ull(c[i])*pw2[n-i+1]%mod; rs2[i] %= mod;
    }
    for (int i = 1; i < n; i++) {
        if (rs[i]*pw[2] == (s[i+1]-s[1])*pw[n-i+1]) {
            if ((rs[n]-rs[i+1])*pw[i+2] == (s[n]-s[i+1])*pw[1]) {
                if (rs2[i]*pw2[2]%mod == (s2[i+1]+mod-s2[1])*pw2[n-i+1]%mod) {
                    if ((rs2[n]+mod-rs2[i+1])*pw2[i+2]%mod == (s2[n]+mod-s2[i+1])*pw2[1]%mod) {
                        ans[++tot] = (a[i]+a[1]) % m;
                    }
                }
            }
        }
    }
    int ok = 1;
    for (int i = 1; i <= n; i++) {
        if (!st.count(((a[n]+a[1]-a[i])%m+m)%m)) {
            ok = 0;
        }
    }
    if (ok) ans[++tot] = (a[n]+a[1])%m;
    sort(ans+1, ans+tot+1);
    cout << tot << endl;
    for (int i = 1; i <= tot; i++) cout << ans[i] << " ";
    if (tot) cout << endl;
    return 0;
}