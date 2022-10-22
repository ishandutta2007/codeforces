#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, m, k;
int xs[N];
int p[N];
set< int > q[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

int OK = 0;

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if((int)q[x].size() < (int)q[y].size()) swap(x, y);
    for(int i : q[y]) {
        q[x].insert(i);
    }
    p[y] = x;
    if((int)q[x].size() == k) {
        OK = 1;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1;i <= k;i++) {
        scanf("%d", &xs[i]);
    }

    vector< pair< int, pii > > es(m);

    for(int u, v, w, i = 0;i < m;i++) {
        scanf("%d %d %d", &u, &v, &w);
        es[i] = {w, {u, v}};
    }

    sort(es.begin(), es.end());

    for(int v = 1;v <= n;v++) {
        p[v] = v;
    }

    for(int i = 1;i <= n;i++) {
        q[xs[i]].insert(xs[i]);
    }

    for(pair< int, pii > ei : es) {
        int w, u, v;
        w = ei.first;
        tie(u, v) = ei.second;
        if(find(u) == find(v)) continue;
        merge(u, v);
        if(OK) {
            for(int i = 0;i < k;i++) {
                printf("%d ", w);
            }
            printf("\n");
            return 0;
        }
    }

    return 0;
}