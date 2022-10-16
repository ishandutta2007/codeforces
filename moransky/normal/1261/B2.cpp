#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 5;

int n, a[N], m;

PII b[N];

vector<PII> g[N];

bool inline cmp(PII x, PII y) {
    if (x.fi != y.fi) return x.fi > y.fi;
    return x.se < y.se;
}

bool inline cmp2(PII x, PII y) {
    return x.se < y.se;
}

struct Q{
    int p, id;
};

vector<Q> q[N];

int ans[N], c[N];

void inline add(int x, int k) {
    for (; x <= n; x += x & -x) c[x] += k;
}

int inline kth(int k) {
    int p = 0;
    for (int i = 18; ~i; i--) {
        if (p + (1 << i) <= n && c[p + (1 << i)] < k) {
            p |= 1 << i;
            k -= c[p];
        }
    }
    return p + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = mp(a[i], i);
    sort(b + 1, b + 1 + n, cmp);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int k, p; scanf("%d%d", &k, &p);
        q[k].pb((Q) { p, i });
    }
    for (int i = 1; i <= n; i++) {
        add(b[i].se, 1);
        for (int j = 0; j < q[i].size(); j++) {
            Q v = q[i][j];
            ans[v.id] = a[kth(v.p)];
        }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}