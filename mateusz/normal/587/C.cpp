#include <bits/stdc++.h>

using namespace std;

const int N = 100005, LOG = 17, BASE = 131072, INF = 1e9;

int depth[N];
vector<int> res[N];
bool vis[N];
int city[N];
int m, q;
int tree[2 * BASE];
vector<int> queries[N], people[N];
int from[N], to[N], szajs[N];
int czasw[N];
int czaswy[N];
int odl[LOG + 1][N];
int n,a,b,czas;
bool odw[N];
int poziom[N];
vector<int>V[N];
int suma;
void DFS(int w)
{
    czasw[w]=++czas;
    odw[w]=1;
    for(int i=0;i<V[w].size();i++)
    {
        int u=V[w][i];

        if(odw[u]==0)
        {
            odl[0][u]=w;
            poziom[u]=poziom[w]+1;
            DFS(u);
        }
    }
    czaswy[w]=++czas;
}

bool przodek(int w,int u)
{
    if(czasw[w]<=czasw[u]&&czaswy[w]>=czaswy[u])
    return 1;
    return 0;
}



int LCA(int w,int u)
{
    if(przodek(w,u))return w;
    if(przodek(u,w))return u;
    int wys=LOG;
    int wierz=u;

    while(wys>=0)
    {
        if(przodek(odl[wys][wierz],w))wys--;
        else
        wierz=odl[wys][wierz];
    }

    return odl[0][wierz];

}

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

void DFS2(int w) {
    vis[w] = true;

    sort(people[w].begin(), people[w].end());
    reverse(people[w].begin(), people[w].end());
    if (people[w].size() > 0) {
//         cerr << "w = " << w << ", people[w].back() = " << people[w].back() << endl;
        insert(depth[w], people[w].back());
    }

    for (int i = 0; i < queries[w].size(); i++) {
        int id = queries[w][i];
//         cerr << "Zapytanie, w = " << w << ", id = " << id << endl;
        int u = from[id] == w ? to[id] : from[id];
        int lca = LCA(w, u);
        int a = szajs[id];
        vector<int> toUndo;
        for (int j = 1; j <= a; j++) {
            int queryResult = query(depth[lca], depth[w]);
//             cerr << "queryResult " << queryResult << endl;
            if (queryResult == INF) {
                break;
            }
            res[id].push_back(queryResult);
            toUndo.push_back(queryResult);
            int itscity = city[queryResult];
            people[itscity].pop_back();
            if(people[itscity].size() > 0) {
                insert(depth[itscity], people[itscity].back());
            } else {
                insert(depth[itscity], INF);
            }
        }
        for (int i = toUndo.size() - 1; i >= 0; i--) {
            int itscity = city[toUndo[i]];
            people[itscity].push_back(toUndo[i]);
            insert(depth[itscity], toUndo[i]);
        }
    }

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            depth[u] = depth[w] + 1;
            DFS2(u);
        }
    }

    insert(depth[w], INF);

}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < 2 * BASE; i++) {
        tree[i] = INF;
    }
    for(int i=0;i<LOG + 1;i++)
    for(int j=1;j<=n;j++)
    odl[i][j]=1;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &city[i]);
        people[city[i]].push_back(i);
    }
    DFS(1);

    for(int i=1;i<LOG + 1;i++)
    {
            for(int j=1;j<=n;j++)
        {

            odl[i][j]=odl[i-1][odl[i-1][j]];

        }

    }


    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &from[i], &to[i], &szajs[i]);
        queries[from[i]].push_back(i);
        queries[to[i]].push_back(i);
    }

    DFS2(1);

    for (int i = 1; i <= q; i++) {
        sort(res[i].begin(), res[i].end());
        int x = 0;
        int last = -1;
        for (int j = 0; j < res[i].size(); j++) {
            if (res[i][j] == last) {
                continue;
            }
            x++;
            if (x == szajs[i]) {
                break;
            }
            last = res[i][j];
        }
        printf("%d ", x);
        x = 0;
        last = -1;
        for (int j = 0; j < res[i].size(); j++) {
            if (res[i][j] == last) {
                continue;
            }
            printf("%d ", res[i][j]);
            x++;
            if (x == szajs[i]) {
                break;
            }
            last = res[i][j];
        }
        printf("\n");
    }

}