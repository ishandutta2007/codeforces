#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, k;
bool mark[N];
vec< int > g[N];
int cnt[N];
int root = -1;

void dfs1(int v, int par = -1) {
    cnt[v] = mark[v];
    int mx = 0;
    for(int to : g[v]) {
        if(to == par) continue;
        dfs1(to, v);
        cnt[v] += cnt[to];
        mx = max(mx, cnt[to]);
    }
    mx = max(mx, 2 * k - cnt[v]);
    if(mx <= k && root == -1) {
        root = v;
    }
}

vec< vec< int > > tot;
vec< int > add;

void dfs2(int v, int par = -1) {
    if(mark[v]) {
        add.push_back(v);
    }
    for(int to : g[v]) {
        if(to == par || to == root) continue;
        dfs2(to, v);
    }
}

int main() {

    scanf("%d %d", &n, &k);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int x, i = 0;i < k+k;i++) {
        scanf("%d", &x);
        mark[x] = 1;
    }

    dfs1(1);

    for(int to : g[root]) {
        add.clear();
        dfs2(to);
        tot.push_back(add);
    }

    int sz = (int)tot.size();

    set< pii > Q;
    set< pii > :: iterator it;

    for(int i = 0;i < sz;i++) {
        Q.insert( make_pair( (int)tot[i].size(), i ) );
    }

    printf("1\n%d\n", root);

    while((int)Q.size() > 1) {
        it = --Q.end();
        int u = (it--)->second;
        int v = it->second;
        if(tot[u].empty() || tot[v].empty()) break;
        Q.erase( make_pair( (int)tot[u].size(), u ) );
        Q.erase( make_pair( (int)tot[v].size(), v ) );
        printf("%d %d %d\n", tot[u].back(), tot[v].back(), root);
        tot[u].pop_back();
        tot[v].pop_back();
        Q.insert( make_pair( (int)tot[u].size(), u ) );
        Q.insert( make_pair( (int)tot[v].size(), v ) );
    }

    for(auto arr : tot) {
        if(arr.empty()) continue;
        printf("%d %d %d\n", arr.back(), root, root);
    }

    return 0;
}