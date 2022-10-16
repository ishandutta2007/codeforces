#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define RED 1
#define BLUE 2

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000010;

vi adj[maxn];
int deg[maxn];
vi teams[maxn];

int color_p[maxn];
int my_team[maxn];
int color_t[maxn];
bool mk[maxn];

int MTEAM;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    MTEAM = 0;

    set<pii> pq;

    for (int i = 1; i <= n; ++i){
        int t; cin >> t;
        for (int j = 0; j < t; ++j){
            int v; cin >> v;
            teams[i].push_back(v);
            MTEAM = max(MTEAM, v);
        }

        pq.insert({deg[i], i});
    }

    while (!pq.empty()){
        pii big = *pq.rbegin();
        pq.erase(big);

        int u = big.second;
        mk[u] = true;

        if (!color_p[u]){
            color_p[u] = RED;
        }

        for (auto v : adj[u]){
            if (mk[v]) continue;

            pq.erase({deg[v], v});
            deg[v]--;
            pq.insert({deg[v], v});

            if (!color_p[v])
                color_p[v] = 3 - color_p[u];
        }

        for (auto t : teams[u]){
            if (color_t[t] == color_p[u]){
                my_team[u] = t;
                break;
            }
        }

        if (!my_team[u]){
            for (auto t : teams[u]){
                if (!color_t[t]){
                    color_t[t] = color_p[u];
                    my_team[u] = t;
                    break;
                }
            }
        }

        if (!my_team[u])
            my_team[u] = teams[u][0];
    }

    for (int i = 1; i <= n; ++i)
        cout << my_team[i] << " ";
    cout << endl;

    for (int i = 1; i <= MTEAM; ++i){
        if (!color_t[i]) cout << RED << " ";
        else cout << color_t[i] << " ";
    }

    cout << endl;

    return 0;
}