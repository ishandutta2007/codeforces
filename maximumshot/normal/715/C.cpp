#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int M, RM;

inline int magic(int x) { return (x % M + M) % M; }
inline int sum(int a, int b) { return (a + b) % M; }
inline int raz(int a, int b) { return ((a - b) % M + M) % M; }
inline int mul(int a, int b) { return (1ll * a * b) % M; }

void exc_gcd(int a, int b, int & x, int & y) {
    if(a == 0) {
        x = 0;
        y = 1 % M;
    }else {
        int x1, y1;
        exc_gcd(b % a, a, x1, y1);
        x = raz(y1, mul(b / a, x1));
        y = x1;
    }
}

inline int get_reverse() {
    int x, y;
    exc_gcd(10, M, x, y);
    return x;
}

int const N = 100005;

int n;
ll result;
vec< pii > g[N];
bool used[N];
int sz[N];
int du[N];
int ud[N];
int h[N];
int power10[N];
int rev_power10[N];

void dfs_cnt(int v, int par = -1) {
    sz[v] = 1;
    for(pii iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        dfs_cnt(to, v);
        sz[v] += sz[to];
    }
    //cout << "sz(" << v << ") = " << sz[v] << "\n";
}

void find_centroid(int v, int & centroid, int total_size, int par = -1) {
    //cout << v << ", ";
    int mx = total_size - sz[v];
    for(pii iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        find_centroid(to, centroid, total_size, v);
        mx = max(mx, sz[to]);
    }
    if(mx <= total_size / 2 && centroid == -1) {
        centroid = v;
    }
}

// magic(-mul(ud[v], rev_power10[h[v]]))

void build_tree(int v, int pw = -1, int par = -1) {
    //cout << v << ", ";
    if(par != -1) {
        h[v] = h[par] + 1;
        ud[v] = sum(mul(ud[par], 10), pw);
        du[v] = sum(mul(power10[h[v] - 1], pw), du[par]);
        if(ud[v] == 0) {
            //cout << v << " ";
            result++;
        }
        if(du[v] == 0) {
            //cout << v << " ";
            result++;
        }
        //cout << "\n";
    }
    for(pii iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        build_tree(to, iter.second, v);
    }
}

void add(int v, map< int, int > & global, int key, int par = -1) {
    global[du[v]] += key;
    for(pii iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        add(to, global, key, v);
    }
 }

void rec(int v, map< int, int > & global, int par = -1) {
    result += global[magic(-mul(ud[v], rev_power10[h[v]]))];
    for(pii iter : g[v]) {
        int to = iter.first;
        if(to == par || used[to]) continue;
        rec(to, global, v);
    }
}

void global_dfs(int v) {

    //cout << "\n" << v << " !\n";

    dfs_cnt(v);

    int root = -1;

    //cout << "candidates : {";

    find_centroid(v, root, sz[v]);

    //cout << "}\n";

    //cout << "root = " << root << "\n";

    ud[root] = du[root] = 0;
    h[root] = 0;

    //cout << "visit {";

    build_tree(root);

    //cout << "}\n";

    map< int, int > global;

    for(pii iter : g[root]) {
        int to = iter.first;
        if(used[to]) continue;
        add(to, global, 1, root);
    }

    for(pii iter : g[root]) {
        int to = iter.first;
        if(used[to]) continue;
        add(to, global, -1, root);
        rec(to, global, root);
        add(to, global, 1, root);
    }

    used[root] = 1;

    for(pii iter : g[root]) {
        int to = iter.first;
        if(!used[to]) global_dfs(to);
    }
}

bool solve() {

    scanf("%d %d", &n, &M);

    RM = get_reverse(); // mul(10, RM) == 1

    //cout << "RM = " << RM << "\n";

    power10[0] = rev_power10[0] = 1 % M;

    for(int i = 1;i < N;i++) {
        power10[i] = mul(power10[i - 1], 10);
        rev_power10[i] = mul(rev_power10[i - 1], RM);
    }

    for(int u, v, w, i = 1;i < n;i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    global_dfs(0);

    printf("%I64d\n", result);

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}