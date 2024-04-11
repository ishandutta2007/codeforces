#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

typedef long long lld;

const lld MAX=1e16;
int N,M,S,E,T[1001],C[1001]; lld D[1001],dist[1001],ans;
vector <int> con[1001],cost[1001];
priority_queue < pair<lld,int> > que,que2;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    int a,b,c;
    pair<lld,int> q,top;
    scanf("%d%d%d%d",&N,&M,&S,&E);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&a,&b,&c);
        con[a].push_back(b), cost[a].push_back(c);
        con[b].push_back(a), cost[b].push_back(c);
    }
    for (i=1;i<=N;i++) scanf("%d%d",T+i,C+i), D[i] = MAX;
    D[S] = 0; que.push(make_pair(0,S));
    while (!que.empty()){
        q = que.top();
        que.pop();
        if (D[q.second] < -q.first) continue;
        for (i=1;i<=N;i++) dist[i] = MAX;
        dist[q.second] = 0;
        que2.push(make_pair(0,q.second));
        while (!que2.empty()){
            top = que2.top();
            que2.pop();
            if (dist[top.second] < -top.first || -top.first > T[q.second]) continue;
            if (D[top.second] > D[q.second]+C[q.second]){
                D[top.second] = D[q.second]+C[q.second];
                que.push(make_pair(-D[top.second],top.second));
            }
            for (i=con[top.second].size();i--;){
                k = con[top.second][i];
                if (dist[k] > dist[top.second]+cost[top.second][i])
                    dist[k] = dist[top.second]+cost[top.second][i], que2.push(make_pair(-dist[k],k));
            }
        }
    }
    printf("%lld",D[E]==MAX?-1:D[E]);
}