#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
vec< int > g[N];
pii edge[N];

inline int get_to(int id, int v) {
    return edge[id].first == v ? edge[id].second : edge[id].first;
}

int tin[N];
int fup[N];
int timer = 0;
int is_bridge[N];
int used[N];
vec< pii > segments;
vec< int > add[N];
vec< int > del[N];

void dfs(int v, int par = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for(int id : g[v]) {
        int to = get_to(id, v);
        if(to == par) continue;
        if(used[to]) {
            fup[v] = min(fup[v], tin[to]);
        }else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] > tin[v]) {
                is_bridge[id] = 1;
            }
        }
    }
}

void go(int v, int& mn, int & mx) {
    used[v] = 1;
    mn = min(mn,v);
    mx = max(mx, v);
    for(int id : g[v]) {
        if(is_bridge[id]) continue;
        int to = get_to(id, v);
        if(!used[to]) {
            go(to, mn, mx);
        }
    }
}

int link[N];
int cnt[N];
ll sum[N];

void Add(int pos, int val) {
    for(int cur = pos;cur <= n;cur |= (cur + 1)) {
        cnt[cur]++;
        sum[cur] += val;
    }
}

pair< int, ll > get(int l, int r) {
    int res_cnt = 0;
    ll res_sum = 0;
    for(int cur = r;cur > 0;cur = (cur & (cur + 1)) - 1) {
        res_cnt += cnt[cur];
        res_sum += sum[cur];
    }
    return make_pair(res_cnt, res_sum);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(i);
        g[v].push_back(i);
        edge[i] = make_pair(u, v);
    }

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        dfs(i);
    }

    memset(used, 0, sizeof(int) * N);

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            int mn = inf;
            int mx = -inf;
            go(i, mn, mx);
            if(mn < mx) {
                segments.push_back(make_pair(mn, mx));
                add[mn].push_back((int)segments.size() - 1);
                del[mx].push_back((int)segments.size() - 1);
            }
        }
    }

    multiset< int > Q;
    multiset< int > :: iterator fnd;
    Q.insert(n + 1);

    for(int i = n;i >= 1;i--) {
        for(int j : add[i]) {
            Q.insert(segments[j].second);
        }
        link[i] = *(Q.begin()) - 1;
    }

    int q;

    scanf("%d", &q);

    vec< ll > res(q + 1);
    vec< vec< pii > > ask(n + 1);
    vec< pii > query(q + 1);

    for(int l, r, it = 1;it <= q;it++) {
        scanf("%d %d", &l, &r);
        ask[l].push_back(make_pair(it, r));
        if(r + 1 <= n) {
            ask[r + 1].push_back(make_pair(-it, r));
        }
        query[it] = make_pair(l, r);
    }

    for(int i = n;i >= 1;i--) {
        Add(link[i], link[i]);
        for(pii iter : ask[i]) {
            int r, id;
            tie(id, r) = iter;

            int tmp_cnt;
            ll tmp_sum;

            tie(tmp_cnt, tmp_sum) = get(i, r);
            int l = i;
            res[abs(id)] += 1ll * (id > 0 ? 1 : -1) * (tmp_sum + 1ll * (n - i + 1 - tmp_cnt) * r);
        }
    }

    for(int i = 1;i <= q;i++) {
        int l, r;
        tie(l, r) = query[i];
        res[i] += r - l + 1 - 1ll * (l + r) * (r - l + 1) / 2;
#ifdef debug
        printf("%lld\n", res[i]);
#else
        printf("%I64d\n", res[i]);
#endif
    }

    return 0;
}