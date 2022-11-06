#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int ans, n, m, a, b, c;
long long pod[N], wynik[N], l;
int size[N], rep[N], tab[N], przodek[N];
bool odw[N], wziety[N];
vector<pair<int, int> > V[N];
vector<long long> suf[N];

void DFS(int w)
{
    odw[w] = true;
    for(int i = 0; i < V[w].size(); i++)
    {
        int u = V[w][i].first;
        if(odw[u])
        {
            przodek[w] = u;
            swap(V[w][i], V[w].back());
            i--;
            V[w].pop_back();
        }
        else
        {
            DFS(u);
            pod[w] = max(pod[w], pod[u] + V[w][i].second);
        }
    }
}

void DFS2(int w, long long MXpref)
{
    for(int i = 0; i < V[w].size(); i++)
    {
        int u = V[w][i].first;
        int kr = V[w][i].second;
        wynik[u] = max(pod[u], kr + max(MXpref, suf[w][i + 1]));
        DFS2(u, kr + max(MXpref, suf[w][i + 1]));
        MXpref = max(MXpref, pod[u] + kr);
    }
}
bool cmp(int a, int b)
{
    return wynik[a] < wynik[b];
}
int find(int w)
{
    return rep[w] == w? w: rep[w] = find(rep[w]);
}
void Union(int a, int b)
{
    size[a] += size[b];
    rep[b] = a;
}
void add(int w)
{
    rep[w] = w;
    size[w] = 1;
    for(int i = 0; i < V[w].size(); i++)
    {
        int u = V[w][i].first;
        if(wziety[u] == true)
            Union(w, find(u));
    }   
    ans = max(ans, size[w]);
    wziety[w] = true;
}
inline void usun(int w)
{
    wziety[w] = false;
    size[find(w)]--;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    DFS(1);
    wynik[1] = pod[1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= V[i].size(); j++)
            suf[i].push_back(0);
        for(int j = V[i].size() - 1; j >= 0; j--)
            suf[i][j] = max(suf[i][j + 1], pod[V[i][j].first] + V[i][j].second);
    }
    DFS2(1, 0);
    for(int i = 1; i <= n; i++)
        if(przodek[i] != 0)
            V[i].push_back({przodek[i], 0});
    for(int i = 1; i <= n; i++)
        tab[i] = i;
    sort(tab + 1, tab + 1 + n, cmp);
    scanf("%d", &m);
    while(m--)
    {
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            wziety[i] = false;
            size[i] = 0;
        }
        scanf("%I64d", &l);
        int kon = n;
        for(int i = n; i >= 1; i--)
        {
            while(kon >= i && wynik[tab[kon]] - wynik[tab[i]] > l)
            {
                usun(tab[kon]);
                kon--;
            }
            add(tab[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}