#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 100005
typedef long long lld;
typedef pair<int,int> pii;

int N,M,K,P[MAXN],mom[MAXN];
lld D[MAXN],ans;
bool V[MAXN];
vector <int> con[MAXN],cone[MAXN];
priority_queue <pii> que;

struct EDGE{
    int a,b; lld c;
    EDGE(int a,int b,lld c){ this->a = a; this->b = b; this->c = c; }
    bool operator < (const EDGE &ot)const{
        return c<ot.c;
    }
}; vector <EDGE> edge;

int find(int n){ return mom[n]==n?n:(mom[n]=find(mom[n])); }

int main()
{
    int i,j,k,l,a,b;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&l);
        con[j].push_back(k), cone[j].push_back(l);
        con[k].push_back(j), cone[k].push_back(l);
    }
    for (i=1;i<=N;i++) D[i] = 1e17;
    for (scanf("%d",&K);K--;){
        scanf("%d",&k);
        D[k] = 0, P[k] = k;
        que.push(pii(0,k));
    }
    for (i=1;i<=N;i++){
        for (;;){
            k = que.top().second;
            que.pop();
            if (!V[k]) break;
        }
        V[k] = 1;
        for (j=con[k].size();j--;){
            if (D[con[k][j]] > D[k]+cone[k][j])
                D[con[k][j]] = D[k]+cone[k][j], P[con[k][j]] = P[k],
                que.push(pii(-D[con[k][j]],con[k][j]));
        }
    }
    for (i=1;i<=N;i++){
        for (j=con[i].size();j--;){
            k = con[i][j];
            if (k < i || P[i] == P[k]) continue;
            edge.push_back(EDGE(P[i],P[k],D[i]+D[k]+cone[i][j]));
        }
    }
    sort(edge.begin(),edge.end());
    for (i=1;i<=N;i++) mom[i] = i;
    for (i=0;i<edge.size();i++){
        a = find(edge[i].a), b = find(edge[i].b);
        if (a == b) continue;
        ans += edge[i].c;
        mom[b] = a;
    }
    printf("%I64d\n",ans+D[1]);
}