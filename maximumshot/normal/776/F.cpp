#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

int n, m;
vec< int > g[N];
vec< int > vis[N];
vec< pair< vec< int >, int > > arr;
int sz;

vec< int > add;

void build(int v, int ptr) {
    if(vis[v][ptr]) return;
    vis[v][ptr] = 1;
    add.push_back(v);
    int to = g[v][ptr];
    int nxt = lower_bound(ALL(g[to]), v) - g[to].begin();
    nxt++;
    if(nxt == (int)g[to].size()) {
        nxt = 0;
    }
    build(to, nxt);
}

void buildArray() {
    set< int > q;

    for(int i = 1;i <= n;i++) {
        int j = i % n + 1;
        g[i].push_back(j);
        g[j].push_back(i);
    }

    for(int i = 1;i <= n;i++) {
        sort(ALL(g[i]));
        vis[i].resize((int)g[i].size());
    }

    int cur = 0;
    int ok = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < (int)g[i].size();j++) {
            if(vis[i][j]) continue;
            add.clear();
            build(i, j);
            if(ok) {
                arr.push_back(make_pair(add, cur++));
            }else {
                ok = 1;
            }
        }
    }

    for(auto & i : arr) {
        sort(ALL(i.first));
        i.first.resize(unique(ALL(i.first)) - i.first.begin());
        reverse(ALL(i.first));
    }

    sz = (int)arr.size();
}

void buildTree() {
    for(int i = 0;i < sz;i++) {
        g[i].clear();
    }
    map< pii, int > last;
    for(int i = 0;i < sz;i++) {
        auto & mas = arr[i].first;
        for(int u, v, j = 0;j < (int)mas.size();j++) {
            u = mas[j];
            v = mas[(j + 1) % (int)mas.size()];
            if(u > v) swap(u, v);
            if(last.count(make_pair(u, v))) {
                int ptr = last[ make_pair(u, v) ];
                g[ptr].push_back(arr[i].second);
                g[arr[i].second].push_back(ptr);
            }else {
                last[ make_pair(u, v) ] = arr[i].second;
            }
        }
    }
}

void show() {
    for(int i = 0;i < (int)arr.size();i++) {
        cout << arr[i].second << " : ";
        for(int x : arr[i].first) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
    for(int i = 0;i < (int)arr.size();i++) {
        cout << i << " : ";
        for(int j : g[i]) cout << j << " ";
        cout << "\n";
    }
}

int color[N];
bool used[N];
int cnt[N];

void go(int v, int par = -1) {
    cnt[v] = 1;
    for(int to : g[v]) {
        if(to == par || used[to]) continue;
        go(to, v);
        cnt[v] += cnt[to];
    }
}

void find(int v, int Size, int & centroid, int par = -1) {
    int mx = Size - cnt[v];
    for(int to : g[v]) {
        if(to == par || used[to]) continue;
        find(to, Size, centroid, v);
        mx = max(mx, cnt[to]);
    }
    if(mx <= Size / 2 && centroid == -1) {
        centroid = v;
    }
}

void dfs(int v, int cl) {
    go(v);
//    cout << "root = " << v << "\n";
//    for(int i = 0;i < sz;i++) {
//        cout << cnt[i] << " ";
//    }
//    cout << "\n";
    int centroid = -1;
    find(v, cnt[v], centroid);
//    cout << cl << " color of " << centroid << "\n";
    used[centroid] = 1;
    color[centroid] = cl;
    for(int to : g[centroid]) {
        if(used[to]) continue;
        dfs(to, cl + 1);
    }
}

int F(vec< int > const & v1, vec< int > const & v2) {
    int i = 0;
    int j = 0;
    while(i < (int)v1.size() && j < (int)v2.size()) {
        if(v1[i] < v2[j]) {
            return -1;
        }else if(v1[i] > v2[j]) {
            return 1;
        }else {
            i++;
            j++;
        }
    }
    if(i < (int)v1.size()) {
        return 1;
    }else if(j < (int)v2.size()) {
        return -1;
    }else {
        return 0;
    }
}

bool cmp(pair< vec< int >, int > const & p1, pair< vec< int >, int > const & p2) {
    int tmp = F(p1.first, p2.first);
    if(tmp == -1) {
        return 1;
    }else if(tmp == 1) {
        return 0;
    }else {
        return p1.second < p2.second;
    }
}

int main() {

//    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    buildArray();
    buildTree();

//    show();

    dfs(0, 1);

    sort(ALL(arr), cmp);

    for(int i = 0;i < sz;i++) {
        printf("%d ", color[arr[i].second]);
//        cout << arr[i].second << " ";
    }

//    cout << "\n";

    printf("\n");

    return 0;
}