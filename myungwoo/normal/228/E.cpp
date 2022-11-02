#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N,M,V[101],ans;
vector <int> con[101],conv[101];
queue <int> que;

struct {
    int a,b,c;
} E[10001];

void bfs(int n)
{
    int i,k,q;
    que.push(n);
    V[n] = 1;
    while (!que.empty()){
        q = que.front(); que.pop();
        for (i=con[q].size();i--;){
            k = con[q][i];
            if (!V[k]){
                V[k] = !conv[q][i]?3-V[q]:V[q];
                que.push(k);
            }
        }
    }
}

int main()
{
    int i,j,k,l;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",&j,&k,&l);
        con[j].push_back(k); conv[j].push_back(l);
        con[k].push_back(j); conv[k].push_back(l);
        E[i].a = j, E[i].b = k, E[i].c = l;
    }
    for (i=1;i<=N;i++) if (!V[i]) bfs(i);
    for (i=1;i<=M;i++){
        if ((V[E[i].a]+V[E[i].b])%2 != !E[i].c) break;
    }
    if (i <= M) puts("Impossible");
    else{
        for (i=1;i<=N;i++) if (V[i]&1) ans++;
        printf("%d\n",ans);
        for (i=1;i<=N;i++) if (V[i]&1) printf("%d ",i);
    }
}