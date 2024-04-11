#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, K = 18;
int n, fa[N], a[N], b[N], v[N], weg[N];
int f[1 << K], s[1 << K];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
int unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return 0;
    return fa[x] = y, 1;
}
void upd(int x, int y) {
    if(find(f[x]) == find(y)) {
        f[x] = a[f[x]] < a[y] ? y : f[x];
    } else if(find(s[x]) == find(y)) {
        s[x] = a[s[x]] < a[y] ? y : s[x];
    } else {
        if(a[f[x]] < a[y]) s[x] = f[x], f[x] = y;
        else if(a[s[x]] < a[y]) s[x] = y;
    }
    if(a[f[x]] < a[s[x]]) swap(f[x], s[x]);
    return;
}
void solve() {
    a[0] = -0x3f3f3f3f;
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    a[++n] = 0;
    for(int i = 1; i <= n; i++) b[i] = ((1 << K) - 1) ^ a[i];
    for(int i = 1; i <= n; i++) fa[i] = i;
    sum = -sum;
    while(1) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(find(i) == i) cnt++;
        if(cnt == 1) break;
        for(int i = 0; i < 1 << K; i++) f[i] = s[i] = 0;
        for(int i = 1; i <= n; i++) upd(a[i], i), weg[i] = -1, v[i] = 0;
        for(int i = 0; i < 1 << K; i++) {
            for(int j = 0; j < K; j++) {
                if(!(i >> j & 1)) {
                    int k = i ^ (1 << j);
                    if(f[i]) upd(k, f[i]);
                    if(s[i]) upd(k, s[i]);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            int rt = find(i);
            int id = find(f[b[i]]) == rt ? s[b[i]] : f[b[i]];
            if(weg[rt] < a[i] + a[id]) {
                weg[rt] = a[i] + a[id];
                v[rt] = id;
            }
        }
        for(int i = 1; i <= n; i++) if(v[i] && find(i) == i && find(i) != find(v[i])) sum += weg[i], unite(i, v[i]);
    }
    cout << sum << endl;
    return;
}
int main() {
    solve();
	return 0;
}