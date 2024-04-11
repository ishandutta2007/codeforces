#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 3000;
const int MAXM = MAXN*3+100;
const int INF = 999999999;
struct node{
    int v, f, c;
    int p;
    node *next, *back;
};
template< int maxn >
struct Network_Stream{
    int s, t, Cost;
    node S[maxn*7+100], *adj[maxn+10], *ecnt, *Fa[maxn+10];
    int d[maxn+10], a[maxn+10];
    void addedge(int u,int v,int c,int p){
        ++ecnt;
        ecnt->back = ecnt+1;
        ecnt->next = adj[u];
        ecnt->c = c;
        ecnt->f = 0;
        ecnt->v = v;
        ecnt->p = p;
        adj[u] = ecnt;

        ++ecnt;
        ecnt->back = ecnt-1;
        ecnt->next = adj[v];
        ecnt->c = 0;
        ecnt->f = 0;
        ecnt->v = u;
        ecnt->p = -p;
        adj[v] = ecnt;
    }
    int BFS(){
        a[s] = INF;
        for(int i=0;i<=t;i++)
            d[i] = INF;
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(node *p = adj[u]; p; p=p->next){
                if(p->f < p->c && d[p->v] > d[u] + p->p){
                    d[p->v] = d[u] + p->p;
                    Fa[p->v] = p;
                    a[p->v] = min(a[u], p->c - p->f);
                    que.push(p->v);
                }
            }
        }
        if(d[t] == INF)
            return 0;
        int ns = t;
        while(ns != s){
            Fa[ns]->f += a[t];
            Fa[ns]->back->f -= a[t];
            ns = Fa[ns]->back->v;
        }
        Cost += a[t] * d[t];
        return 1;
    }
    int work(){
        Cost = 0;
        while(BFS());
        return Cost;
    }
    void Init(int _s, int _t){
        s = _s;
        t = _t;
        ecnt = S;
        memset(adj, 0, sizeof adj);
    }
};
Network_Stream <4000> Ps;
int ans[3][MAXN+10];
int main(){
    int n, s, p, a, b;
    scanf("%d%d%d",&n,&p,&s);
    Ps.Init(0, n+3);
    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        Ps.addedge(0, i, 1, 0);
        Ps.addedge(i, n+1, 1, -a);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &b);
        Ps.addedge(i, n+2, 1, -b);
    }
    Ps.addedge(n+1, n+3, p, 0);
    Ps.addedge(n+2, n+3, s, 0);
    Ps.work();
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(node *p=Ps.adj[i];p;p=p->next){
            if(p->v > n && p->f == 1){
                ::ans[p->v-n][++::ans[p->v-n][0]] = i;
                ans -= p->p;
            }
        }
    }
    printf("%d\n", ans);
    for(int i=1;i<=p;i++)
        printf("%d%c", ::ans[1][i], i==p?'\n':' ');
    for(int i=1;i<=s;i++)
        printf("%d%c", ::ans[2][i], i==s?'\n':' ');

    return 0;
}