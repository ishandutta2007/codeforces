#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, ii> llii;

const int Maxn = 200005;

map <ii, ll> dist;
int n, m, k;
vector <ii> neigh[Maxn];

bool Less(const ii &a, const ii &b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    priority_queue <llii> Q;
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c));
        neigh[b].push_back(ii(a, c));
        if (a > b) swap(a, b);
        dist[ii(a, b)] = c; Q.push(llii(-c, ii(a, b)));
    }
    for (int i = 1; i <= n; i++) {
        sort(neigh[i].begin(), neigh[i].end(), Less);
        while (neigh[i].size() > k) neigh[i].pop_back();
    }
    while (!Q.empty()) {
        ll d = -Q.top().first;
        ii v = Q.top().second; Q.pop();
        if (dist[v] != d) continue;
        if (k == 1) { printf("%lld\n", d); return 0; }
        else k--;
        for (int i = 0; i < neigh[v.second].size(); i++) {
            ii u = ii(v.first, neigh[v.second][i].first);
            if (u.first > u.second) swap(u.first, u.second);
            if (u.first == u.second) continue;
            ll cand = d + neigh[v.second][i].second;
            map <ii, ll>::iterator it = dist.find(u);
            if (it == dist.end() || cand < it->second) {
                dist[u] = cand;
                Q.push(llii(-cand, u));
            }
        }
        for (int i = 0; i < neigh[v.first].size(); i++) {
            ii u = ii(neigh[v.first][i].first, v.second);
            if (u.first > u.second) swap(u.first, u.second);
            if (u.first == u.second) continue;
            ll cand = d + neigh[v.first][i].second;
            map <ii, ll>::iterator it = dist.find(u);
            if (it == dist.end() || cand < it->second) {
                dist[u] = cand;
                Q.push(llii(-cand, u));
            }
        }
    }
    return 0;
}