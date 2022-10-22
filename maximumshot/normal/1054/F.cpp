#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

struct pt {
    int x, y;
};

const int N = 1005;

int n;
pt p[N];
vec< int > hor[N], ver[N];
vec< pair< pii, int > > es;
int sz;

vec< vec< int > > g;

bool intersect(pt p1, pt p2, pt p3, pt p4) {
    assert(p1.y == p2.y);
    assert(p3.x == p4.x);
    return min(p1.x, p2.x) < p3.x && p3.x < max(p1.x, p2.x) &&
           min(p3.y, p4.y) < p1.y && p1.y < max(p3.y, p4.y);
}

vec< int > used, mt;

int go(int v) {
    if(used[v]) return 0;
    used[v] = 1;
    for(int to : g[v]) {
        if(mt[to] == -1 || go(mt[to])) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    return 0;
}

void dfs(int v) {
    if(v == -1) return;
    if(used[v]) return;
    used[v] = 1;
    for(int to : g[v]) {
        used[to] = 1;
        dfs(mt[to]);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    for(int i = 1;i <= n;i++) {
        { // left
            int j = -1;
            for(int q = 1;q <= n;q++) {
                if(q == i) continue;
                if(p[q].x != p[i].x) continue;
                if(p[q].y > p[i].y) continue;
                if(j == -1 || p[q].y > p[j].y) j = q;
            }
            if(j == -1) j = i;
            ver[i].push_back(j);
            ver[j].push_back(i);
        }
        { // up
            int j = -1;
            for(int q = 1;q <= n;q++) {
                if(q == i) continue;
                if(p[q].y != p[i].y) continue;
                if(p[q].x > p[i].x) continue;
                if(j == -1 || p[q].x > p[j].x) j = q;
            }
            if(j == -1) j = i;
            hor[i].push_back(j);
            hor[j].push_back(i);
        }
    }

    for(int i = 1;i <= n;i++) {
        sort(ALL(hor[i]));
        hor[i].resize(unique(ALL(hor[i])) - hor[i].begin());

        sort(ALL(ver[i]));
        ver[i].resize(unique(ALL(ver[i])) - ver[i].begin());
    }

    for(int i = 1;i <= n;i++) {
        for(int j : hor[i]) {
            if(i <= j) es.push_back({{i, j}, 0});
        }
        for(int j : ver[i]) {
            if(i <= j) {
                es.push_back({{i, j}, 1});
            }
        }
    }

//    cout << "sz = " << (int)es.size() << "\n";
//    int cur = 0;
//    for(pair<pii, int> pr : es) {
//        cout << "#" << cur++ << " : ";
//        pt p1 = p[ pr.first.first ];
//        pt p2 = p[ pr.first.second ];
//        cout << "(" << "[" << p1.x << ", " << p1.y << "]" << ", " << "[" << p2.x << ", " << p2.y << "]" << ") " << (pr.second ? "ver" : "hor") << "\n";
//    }

    sz = (int)es.size();
    g.resize(sz);

    for(int i = 0;i < sz;i++) {
        if(es[i].second) continue;
        // i - hor
        for(int j = 0;j < sz;j++) {
            if(es[i].second == es[j].second) continue;
            // j - ver

            pt p1, p2, p3, p4;

            p1 = p[ es[i].first.first ];
            p2 = p[ es[i].first.second ];

            p3 = p[ es[j].first.first ];
            p4 = p[ es[j].first.second ];

            if(intersect(p1, p2, p3, p4)) {
//                cout << i << " int " << j << "\n";
                g[i].push_back(j);
            }
        }
    }

    used.resize(sz);
    mt.resize(sz, -1);

    for(int v = 0;v < sz;v++) {
        if(es[v].second) continue;
        used.assign(sz, 0);
        go(v);
    }

    used.assign(sz, 0);
    for(int v = 0;v < sz;v++) {
        if(es[v].second) continue;
        if(mt[v] != -1 || used[v]) continue;
        dfs(v);
    }

    for(int i = 1;i <= n;i++) {
        hor[i].clear();
        ver[i].clear();
    }

    for(int v = 0;v < sz;v++) {
        if(es[v].second) continue;
        if(!used[v]) continue;
        // hor
        int i, j;
        tie(i, j) = es[v].first;
        if(p[i].x > p[j].x) swap(i, j);
        if(i != j)
            hor[i].push_back(j);
    }

    for(int v = 0;v < sz;v++) {
        if(!es[v].second) continue;
        if(used[v]) continue;
        // ver
        int i, j;
        tie(i, j) = es[v].first;
        if(p[i].y > p[j].y) swap(i, j);
        if(i != j)
            ver[i].push_back(j);
    }

    vec< pair< pt, pt > > hh, vv;

    vec< int > in(n + 1);

    for(int i = 1;i <= n;i++) for(int j : hor[i]) in[j]++;

    for(int i = 1;i <= n;i++) {
        if(in[i]) continue;
        int j = i;
        while(!hor[j].empty()) j = hor[j].front();
        hh.push_back({ p[i], p[j] });
    }

    in.assign(n + 1, 0);

    for(int i = 1;i <= n;i++) for(int j : ver[i]) in[j]++;

    for(int i = 1;i <= n;i++) {
        if(in[i]) continue;
        int j = i;
        while(!ver[j].empty()) j = ver[j].front();
        vv.push_back({ p[i], p[j] });
    }

    printf("%d\n", (int)hh.size());

    for(pair< pt, pt > pr : hh) {
        printf("%d %d %d %d\n", pr.first.x, pr.first.y, pr.second.x, pr.second.y);
    }

    hh = vv;

    printf("%d\n", (int)hh.size());

    for(pair< pt, pt > pr : hh) {
        printf("%d %d %d %d\n", pr.first.x, pr.first.y, pr.second.x, pr.second.y);
    }


    return 0;
}