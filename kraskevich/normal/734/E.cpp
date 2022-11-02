#include <bits/stdc++.h>

using namespace std;

struct Dsu {
    vector<int> p;

    Dsu(int n): p(n) {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int v) {
        return p[v] == v ? v : p[v] = get(p[v]);
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        p[a] = b;
    }
};

const int N = 200 * 1000 + 100;

vector<int> g[N];
int dist[N];
int size;

int bfs(int st) {
    fill(dist, dist + size, N);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to); 
            }    
    }
    int v = 0;
    for (int i = 0; i < size; i++)
        if (dist[i] > dist[v])
            v = i;
    return v;           
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Dsu dsu(n);
    vector<int> col(n);
    for (int i = 0; i < n; i++)
        cin >> col[i];
    vector<int> a(n - 1);
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if (col[a[i]] == col[b[i]])
            dsu.unite(a[i], b[i]);        
    }        
    vector<int> roots;
    for (int i = 0; i < n; i++)
        roots.push_back(dsu.get(i));
    sort(roots.begin(), roots.end());
    roots.resize(unique(roots.begin(), roots.end()) - roots.begin());
    for (int i = 0; i < n - 1; i++) {
        int v = lower_bound(roots.begin(), roots.end(), dsu.get(a[i])) - roots.begin();
        int u = lower_bound(roots.begin(), roots.end(), dsu.get(b[i])) - roots.begin();
        if (u != v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    size = roots.size();
    int v = bfs(0);
    int u = bfs(v);
    cout << (dist[u] + 1) / 2 << endl;        
    return 0;
}