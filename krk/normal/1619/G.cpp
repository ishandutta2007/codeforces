#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;
const int Inf = 2000000007;

int T;
int n, k;
int tim[Maxn];
vector <int> neigh[Maxn];
bool tk[Maxn];
map <int, vector <ii> > byX, byY;

void Construct(map <int, vector <ii> > &M)
{
    for (auto it = M.begin(); it != M.end(); it++) {
        auto V = it->second;
        sort(V.begin(), V.end());
        for (int i = 1; i < V.size(); i++)
            if (V[i].first - V[i - 1].first <= k) {
                neigh[V[i].second].push_back(V[i - 1].second);
                neigh[V[i - 1].second].push_back(V[i].second);
            }
    }
}

int Get(int v)
{
    if (tk[v]) return Inf;
    tk[v] = true;
    int res = tim[v];
    for (int i = 0; i < neigh[v].size(); i++)
        res = min(res, Get(neigh[v][i]));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        byX.clear(); byY.clear();
        for (int i = 0; i < n; i++) {
            neigh[i].clear();
            tk[i] = false;
            int x, y; scanf("%d %d %d", &x, &y, &tim[i]);
            byX[x].push_back(ii(y, i));
            byY[y].push_back(ii(x, i));
        }
        Construct(byX);
        Construct(byY);
        deque <int> D;
        for (int i = 0; i < n; i++) if (!tk[i])
            D.push_back(Get(i));
        sort(D.begin(), D.end());
        int pnt = -1;
        while (!D.empty()) {
            pnt++;
            D.pop_back();
            while (!D.empty() && pnt >= D.front())
                D.pop_front();
        }
        printf("%d\n", pnt);
    }
    return 0;
}