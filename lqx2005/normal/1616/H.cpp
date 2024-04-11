#include <bits/stdc++.h>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
const int N = 1.5e5 + 10, P = 998244353;
int n, x, p2[N];
map<int, vector<int> > buc;
int solve(vector<int> a, vector<int> b, int p) {
    if(sz(a) + sz(b) <= 0) return 0;
    if(p < 0) return p2[sz(a) + sz(b)] - 1;
    vector<int> a0, a1, b0, b1;
    for(int x : a) {
        if(x >> p & 1) a1.push_back(x);
        else a0.push_back(x);
    }
    for(int x : b) {
        if(x >> p & 1) b1.push_back(x);
        else b0.push_back(x);
    }
    if(x >> p & 1) {
        return (1ll * (solve(a0, b1, p - 1) + 1) * (solve(a1, b0, p - 1) + 1) % P + P - 1) % P;
    } else {
        int res = (solve(a0, b0, p - 1) + solve(a1, b1, p - 1)) % P;
        (res += 1ll * (p2[sz(b0)] - 1) * (p2[sz(b1)] - 1) % P) %= P;
        (res += 1ll * (p2[sz(a0)] - 1) * (p2[sz(a1)] - 1) % P) %= P;
        return res;
    }
}
int main() {
    cin >> n >> x;
    p2[0] = 1;
    for(int i = 1; i <= n; i++) p2[i] = 2ll * p2[i - 1] % P;
    vector<int> a(n);
    int p = -1;
    for(int i = 0; i < 30; i++) if(x >> i & 1) p = i;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        buc[a[i] >> (p + 1)].push_back(a[i]);
    }
    int ans = 0;
    if(p == -1) {
        for(auto v : buc) (ans += p2[sz(v.y)] - 1) %= P;
        cout << ans << endl;
        return 0;
    }
    for(auto v : buc) {
        vector<int> v0, v1;
        for(int x : v.y) {
            if(x >> p & 1) v1.push_back(x);
            else v0.push_back(x);
        }
        (ans += solve(v0, v1, p - 1)) %= P;
    }
    cout << ans << endl;
    return 0;
}