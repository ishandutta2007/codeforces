#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 1000000000;

int n, m, k;
vector <int> neigh[Maxn];
vector <int> spec;
vector <ii> vals;
int distA[Maxn], distB[Maxn];
map <int, int> M;

void BFS(int v, int dist[])
{
    fill(dist, dist + n + 1, Inf); dist[v] = 0;
    queue <int> Q; Q.push(v);
    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
}

void Insert(int key, int val)
{
    auto it = M.lower_bound(key);
    if (it != M.end() && val <= it->second) return;
    it = M.upper_bound(key);
    while (it != M.begin()) {
        it--;
        if (it->second <= val) M.erase(it++);
        else break;
    }
    M.insert(make_pair(key, val));
}

int Get(int key)
{
    auto it = M.lower_bound(key);
    return it == M.end()? -Inf: it->second;
}

bool Check(int x)
{
    M.clear();
    for (int i = 0; i < vals.size(); i++) {
        if (Get(x - vals[i].first) + vals[i].second >= x) return true;
        Insert(vals[i].second, vals[i].first);
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int a; scanf("%d", &a);
        spec.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    BFS(1, distA); BFS(n, distB);
    for (int i = 0; i < spec.size(); i++) {
        int v = spec[i];
        vals.push_back(ii(distA[v], distB[v]));
    }
    int l = 0, r = distA[n] - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (Check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}