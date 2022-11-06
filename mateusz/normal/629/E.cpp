#include<bits/stdc++.h>
using namespace std;
int czasw[100005];
int czaswy[100005];
int odl[18][100005];
int n,a,b,czas;
bool odw[100005];
int poziom[100005];
vector<int>V[100005];
int suma;
long long prefix[100005];
int pod[100005];
long long sumaPod[100005];
void DFS(int w)
{
    czasw[w]=++czas;
    odw[w]=1;
    pod[w]=1;
    for(int i=0;i<V[w].size();i++)
    {
        int u=V[w][i];

        if(odw[u]==0)
        {
            odl[0][u]=w;
            poziom[u]=poziom[w]+1;
            DFS(u);
            pod[w] += pod[u];
            sumaPod[w] += sumaPod[u];
        }
    }
    sumaPod[w] += pod[w];
    czaswy[w]=++czas;
}

bool przodek(int w,int u)
{
    if(czasw[w]<=czasw[u]&&czaswy[w]>=czaswy[u])
        return 1;
    return 0;
}

void DFS2(int w, long long s) {
    odw[w] = 1;
    prefix[w] = s;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!odw[u]) {
            DFS2(u, s + sumaPod[w] - sumaPod[u] - pod[w] + n - pod[u]);
        }
    }
}

int LCA(int w,int u)
{
    if(przodek(w,u))return w;
    if(przodek(u,w))return u;
    int wys=16;
    int wierz=u;

    while(wys>=0)
    {
        if(przodek(odl[wys][wierz],w))wys--;
        else
            wierz=odl[wys][wierz];
    }

    return odl[0][wierz];

}

int main()
{
    int c;
    cin>>n >> c;
    for(int i=0;i<17;i++)
        for(int j=1;j<=n;j++)
            odl[i][j]=1;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }

        DFS(1);
    for (int i = 1; i <= n; i++) odw[i] = 0;
        DFS2(1, 0);
    for(int i=1;i<16;i++)
    {
        for(int j=1;j<=n;j++)
        {

            odl[i][j]=odl[i-1][odl[i-1][j]];

        }

    }
    int z;
    int h=1;
    long long duzaSuma = 0;
    for (int i = 1; i <= n; i++) duzaSuma += sumaPod[i];

    for (int i = 1; i <= c; i++) {
        cin >> a >> b;
        int lca = LCA(a, b);
        if (lca != a && lca != b) {
            cout << fixed << setprecision(10) << (long double)(sumaPod[a] - pod[a]) / (pod[a]) + (long double)(sumaPod[b] - pod[b]) / (pod[b]) + poziom[a] + poziom[b] - 2 * poziom[lca] + 1 << endl;
        } else {
            if (!przodek(a, b)) {
                swap(a, b);
            }
            int x = 0;
            for (int j = 0; j < V[a].size(); j++) {
                int u = V[a][j];
                if (przodek(u, b) && !(odl[0][a] == u)) {
                    x = u;
                    break;
                }
            }
            cout << fixed << setprecision(10) << (long double)(sumaPod[b] - pod[b]) / (pod[b]) + (long double)(prefix[x] - (n-pod[x])) / (n - pod[x]) + poziom[b] - poziom[a] + 1 << endl;
        }
    }
    return 0;
}