#include <stdio.h>
#include <vector>
using namespace std;

int N,C[201],in[201],itmp[201],ans=1e9;
vector <int> list[4],con[201],tmp[4];

void dfs(int t,int mv)
{
    int i,k;
    while (!list[t].empty()){
        k = list[t].back(); list[t].pop_back();
        for (i=con[k].size();i--;){
            if (!--in[con[k][i]]) list[C[con[k][i]]].push_back(con[k][i]);
        }
    }
    bool sw=0;
    for (i=1;i<4;i++) sw |= !list[i].empty();
    if (sw) dfs(t%3+1,mv+1);
    else if (ans > mv)
        ans = mv;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",C+i);
    for (i=1;i<=N;i++){
        for (scanf("%d",&j);j--;) scanf("%d",&k), con[k].push_back(i), in[i]++;
    }
    for (i=1;i<=N;i++) if (!in[i]) list[C[i]].push_back(i);
    for (i=1;i<4;i++) tmp[i] = list[i];
    for (i=1;i<=N;i++) itmp[i] = in[i];
    for (i=1;i<4;i++) if (!list[i].empty()){
        dfs(i,0);
        for (j=1;j<4;j++) list[j] = tmp[j];
        for (j=1;j<=N;j++) in[j] = itmp[j];
    }
    printf("%d",ans+N);
}