# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;
const int N = 100010;
const int LOG = 18;
vector<int> g[N];

int dep[N], F[N][LOG];
vector<int> s[N][LOG];

void combine(vector<int> &c, const vector<int> &a,const vector<int> &b) {
    size_t i = 0, j = 0; c.clear();
    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) { c.push_back(a[i]); i++; j++; }
        else c.push_back((a[i] < b[j]) ? a[i++] : b[j++]);
    }
    while(i < a.size()) c.push_back(a[i++]);
    while(j < b.size()) c.push_back(b[j++]);
    if(c.size() > 10) c.resize(10);
}

void combine(vector<int> &c, const vector<int> &e) {
    vector<int> tmp(c);
    combine(c, tmp, e);
}

void DFS(int x) {
    for(int i = 1; i < LOG; ++i) 
        F[x][i] = F[F[x][i-1]][i-1];
    for(int i = 1; i < LOG; ++i) 
        combine(s[x][i], s[x][i-1], s[F[x][i-1]][i-1]);
    for(size_t k = 0; k < g[x].size(); ++k) {
        int y = g[x][k];
        if(dep[y] == 0) {
            dep[y] = dep[x] + 1;
            F[y][0] = x;
            DFS(y);
        }
    }
}

void query(int x,int y,int lim) {
    vector<int> ans;
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = LOG - 1; i >= 0; --i)
        if(dep[F[x][i]] >= dep[y]) {
            combine(ans, s[x][i]);
            x = F[x][i];
        }
    for(int i = LOG - 1; i >= 0; --i)
        if(F[x][i] != F[y][i]) {
            combine(ans, s[x][i]);
            combine(ans, s[y][i]);
            x = F[x][i];
            y = F[y][i];
        }
    if(x != y) {
        combine(ans, s[x][0]);
        combine(ans, s[y][0]);
        x = F[x][0];
        y = F[y][0];
    }
    combine(ans, s[x][0]);
    if((int)ans.size() > lim) ans.resize(lim);
    printf("%d", (int)ans.size());
    for(size_t k = 0; k < ans.size(); ++k)
        printf(" %d", ans[k]);
    puts("");
}

int main() {
    int n, m, q, u, v, a, x;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        s[x][0].push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        sort(s[i][0].begin(), s[i][0].end());
        if(s[i][0].size() > 10) s[i][0].resize(10);
    }
    dep[1] = 1;
    F[1][0] = 1;
    DFS(1);
    while(q--) {
        scanf("%d%d%d", &u, &v, &a);
        query(u, v, a);
    }
}