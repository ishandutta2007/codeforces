#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 200005

int N,S[MAXN],mom[MAXN],ans=1e9;
vector <int> con[MAXN],cost[MAXN],list;
queue <int> que;

void init()
{
    int i,k,q;
    que.push(1); mom[1] = 1;
    while (!que.empty()){
        q = que.front(); que.pop();
        for (i=con[q].size();i--;){
            k = con[q][i];
            if (mom[k]) continue;
            mom[k] = q;
            que.push(k); S[1] += cost[q][i];
        }
    }
}

void bfs()
{
    int i,k,q;
    que.push(1);
    while (!que.empty()){
        q = que.front(); que.pop();
        for (i=con[q].size();i--;){
            k = con[q][i];
            if (mom[k] != q) continue;
            if (cost[q][i]) S[k] = S[q]-1;
            else S[k] = S[q]+1;
            que.push(k);
        }
    }
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<N;i++){
        scanf("%d%d",&j,&k);
        con[j].push_back(k), cost[j].push_back(0);
        con[k].push_back(j), cost[k].push_back(1);
    }
    init();
    bfs();
    for (i=1;i<=N;i++){
        if (ans > S[i]) ans = S[i], list.clear();
        if (ans == S[i]) list.push_back(i);
    }
    printf("%d\n",ans);
    for (i=0;i<list.size();i++) printf("%d ",list[i]);
}