#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a;
    int b; 
    int len;
    int id;

    bool operator<(const Edge& e) const {
        return len < e.len;
    }
};

const int N = 1001;

vector<Edge> edges;
int col[N];
int comp[N];
vector<int> at[N];
int n, m;

int solve(int l, int r) {
    fill(col, col + n, 0);
    for (int i = 0; i < n; i++)
        comp[i] = i;
    for (int i = 0; i < n; i++) {
        at[i].clear();
        at[i].push_back(i);    
    }
    int ans = -1;
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (e.id >= l && e.id <= r) {
            int a = e.a;    
            int b = e.b;
            if (comp[a] == comp[b]) {
                if (col[a] == col[b]) {
                    ans = e.len;
                    break;         
                }
            } else {
                if (at[comp[b]].size() > at[comp[a]].size())
                    swap(a, b);
                if (col[a] == col[b])
                    for (int v : at[comp[b]])
                        col[v] = 1 - col[v];
                int cb = comp[b];
                for (int v : at[cb]) {
                    at[comp[a]].push_back(v);
                    comp[v] = comp[a];
                }        
                at[cb].clear();
            }
        }        
    }
    return ans;
}

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].len);
        edges[i].id = i;
        edges[i].a--;
        edges[i].b--;
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for (int i = 0; i < q; i++) {   
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        printf("%d\n", solve(l, r));
    }    
    return 0;
}