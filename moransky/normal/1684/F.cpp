// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, a[N], L[N], R[N], d[N], t, pre[N], suf[N], cnt[N];

set<int> p[N];
vector<int> rt[N], lt[N], lim[N];

set<int> s;

bool ban[N];

void inline clr() {
    s.clear();
    for (int i = 0; i <= n; i++) lim[i].clear(), p[i].clear(), rt[i].clear(), lt[i].clear(), ban[i] = 0, cnt[i] = suf[i] = pre[i] = 0;
    t = 0;
}



void inline work() {
    int pr = n; s.clear();
    for (int i = n, j = n; i; i--) {
        for (int v: rt[i]) s.insert(v);
        if (s.size() && *s.begin() <= pre[i]) {
            ban[i] = 1;
        }
        if (s.size()) {
            int u = *s.begin();
            int v = *p[a[i]].lower_bound(u);
            if (v < i) {
            //    cout << i << "!!!" << v << endl;
                lim[i - 1].pb(v + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ban[i]) {
            pr = i;
            break;
        }
    }
    if (pr == n) {
        puts("0");
        return;
    }
    for (int i = n; i; i--) {
        suf[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        ban[i] = 0;
    }

    s.clear();
    for (int i = 1; i <= n; i++) {
        for (int v: lt[i]) s.insert(v);
        if (suf[i] && s.size() && *--s.end() >= suf[i]) {
            ban[i] = 1;
        }
    }
    int sf = 1;
    for (int i = n; i; i--) {
        if (ban[i]) {
            sf = i;
            break;
        }
    }

   //cout << pr << "---" << sf << "??\n";

    s.clear();
    int ans = 2e9;
    for (int i = n, j = pr; i >= sf; i--) {
        for (int v: lim[i]) {
            s.insert(v);
        }
        while (j > i) {
            j--;
        }
        while (j && (s.size() && *s.begin() <= j)) {
            j--;
        }
        if (!j) break;
        //cout << j << " " << i << "??\n";
        chkMin(ans, i - j + 1);
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        t = 0;
        for (int i = 1; i <= n; i++) read(a[i]), d[++t] = a[i];
        sort(d + 1, d + 1 + t);
        t = unique(d + 1, d + 1 + t) - d - 1;
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(d + 1, d + 1 + t, a[i]) - d;
            pre[i] = 0;
            if (p[a[i]].size()) pre[i] = *--p[a[i]].end();
            p[a[i]].insert(i);
        }
        for (int i = 1; i <= m; i++) read(L[i]), read(R[i]), rt[R[i]].pb(L[i]), lt[L[i]].pb(R[i]);
        work();
        clr();
    }
    return 0;
}