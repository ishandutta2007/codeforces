#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define MAXN 100005
typedef pair<int,int> pii;

int N,M;
int D[MAXN];
bool V[MAXN];

priority_queue <pii> que;
vector <int> con[MAXN],cont[MAXN];
set <int> time[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k,l,q;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&l);
        con[j].push_back(k); cont[j].push_back(l);
        con[k].push_back(j); cont[k].push_back(l);
    }
    for (i=1;i<=N;i++){
        for (scanf("%d",&j);j--;) scanf("%d",&k), time[i].insert(k);
    }
    for (i=2;i<=N;i++) D[i] = 2e9;
    que.push(pii(0,1));
    while (!que.empty()){
        q = que.top().second; que.pop();
        if (V[q]) continue;
        V[q] = 1;
        while (q < N && time[q].count(D[q])) D[q]++;
        for (i=con[q].size();i--;){
            j = con[q][i], k = cont[q][i];
            if (!V[j] && D[j] > D[q]+k)
                D[j] = D[q]+k, que.push(pii(-D[j],j));
        }
    }
    printf("%d",D[N]==2e9?-1:D[N]);
}