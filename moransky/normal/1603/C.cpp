// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5, P = 998244353;

int n, a[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int cnt[N];
 
vector<int> b;

int inline get(int l, int r) {
    int res = 0;
    int v = a[r];
    for (int i = r - 1; i >= l; i--) {
        int t = (a[i] - 1) / v;
        res += t; 
        v = a[i] / (t + 1);
    }
    return res;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        int ans = 0;
        for (int i = n; i; i--) {
            vector<PII> t;
            for (int v: b) t.pb(mp(v, cnt[v])), cnt[v] = 0;
            b.clear();
            for (PII o: t) {
                int v = o.fi, c = o.se;
                int sz = (a[i] - 1) / v;
                add(ans, 1ll * sz * c % P * i % P);
                int nv = a[i] / (sz + 1);
                cnt[nv] += c;
                if (cnt[nv] == c) b.pb(nv);
            }
            cnt[a[i]]++;
            if (cnt[a[i]] == 1) b.pb(a[i]);
        }
        for (int v: b) cnt[v] = 0;
        b.clear();
        printf("%d\n", ans);
    }
    return 0;
}