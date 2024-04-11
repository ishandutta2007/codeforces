#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;
const int N = 105;

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

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = mp(a[i], i);
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        g[i] = g[i - 1];
        g[i].pb(b[i]);
        sort(g[i].begin(), g[i].end(), cmp2);
    }
    scanf("%d", &m);
    while (m--) {
        int k, p; scanf("%d%d", &k, &p);
        printf("%d\n", g[k][p - 1].fi);
    }
    return 0;
}