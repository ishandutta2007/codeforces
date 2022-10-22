#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

vec< int > g[2 * N], gr[2 * N];
vec< int > List[N];
int n, m;
int r[N];

void add_edge(int u, int v) {

    int ru = u < m ? u + m : u - m;
    int rv = v < m ? v + m : v - m;

    g[u].push_back(v);
    g[rv].push_back(ru);

//    cout << u << " -> " << v << "\n";
//    cout << rv << " -> " << ru << "\n";

    gr[v].push_back(u);
    gr[ru].push_back(rv);
}

int tops[2 * N];
bool used[2 * N];
int sz;

void dfs1(int v) {
    if(used[v]) return;
    used[v] = 1;
    for(int to : g[v]) {
        dfs1(to);
    }
    tops[sz++] = v;
}

int color[2 * N];

void dfs2(int v, int cl) {
    if(used[v]) return;
    used[v] = 1;
    color[v] = cl;
    for(int to : gr[v]) {
        dfs2(to, cl);
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &r[i]);
    }

    // 0 .. m - 1 | m .. 2m - 1

    for(int x, i = 0;i < m;i++) {
        scanf("%d", &x);
        for(int y, j = 0;j < x;j++) {
            scanf("%d", &y);
            List[y].push_back(i);
        }
    }

    for(int i = 1;i <= n;i++) {
        int x = List[i][0];
        int y = List[i][1];
//        cout << i << " : " << r[i] << " !\n";
        if(r[i]) {
            add_edge(x, y);
            add_edge(y, x);
        }else {
            add_edge(x, y + m);
            add_edge(y + m, x);
        }
    }

    for(int i = 0;i < 2 * m;i++) {
        dfs1(i);
    }

    for(int i = 0;i < 2 * m;i++) {
        used[i] = 0;
    }

    for(int i = 0;i < 2 * m;i++) {
        color[i] = -i - 1;
    }

    for(int cl = 0, v, i = sz - 1;i >= 0;i--) {
        v = tops[i];
        if(used[v]) continue;
        dfs2(i, cl);
        cl++;
    }

//    cout << "tops: ";
//    for(int i = 0;i < sz;i++) {
//        cout << tops[i] << " ";
//    }
//    cout << "\n";

//    cout << "cl : ";
//    for(int i = 0;i < m+m;i++) {
//        cout << color[i] << " ";
//    }
//    cout << "\n";

    for(int i = 0;i < m;i++) {
        if(color[i] == color[i + m]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}