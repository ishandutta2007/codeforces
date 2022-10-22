#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int T;
int n, m;
ll c[Maxn];
vector <int> neigh[Maxn];
map <vector <int>, int> M;
ll my[Maxn];

int Get(const vector <int> &V)
{
    auto it = M.find(V);
    if (it == M.end()) {
        int siz = M.size();
        my[siz] = 0;
        M.insert(make_pair(V, siz));
        return siz;
    }
    return it->second;
}

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%I64d", &c[i]);
            neigh[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[b].push_back(a);
        }
        M.clear();
        for (int i = 1; i <= n; i++) if (!neigh[i].empty()) {
            sort(neigh[i].begin(), neigh[i].end());
            int id = Get(neigh[i]);
            my[id] += c[i];
        }
        ll g = 0;
        for (int i = 0; i < M.size(); i++)
            g = gcd(g, my[i]);
        printf("%I64d\n", g);
    }
    return 0;
}