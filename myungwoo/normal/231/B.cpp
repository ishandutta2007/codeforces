#include <stdio.h>
#include <vector>
using namespace std;

#define num(n) ((n)-10000)
#define state(n) ((n)+10000)

int N,D,L;
int dy[101][20001],path[101][20001];
vector <int> list;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    scanf("%d%d%d",&N,&D,&L);
    dy[0][state(0)] = 1;
    for (i=0;i<N;i++) for (j=state(-i*L);j<=state(i*L);j++) if (dy[i][j]){
        for (k=1;k<=L;k++){
            if (i&1){
                dy[i+1][state(num(j)-k)] = 1;
                path[i+1][state(num(j)-k)] = k;
            }else{
                dy[i+1][state(num(j)+k)] = 1;
                path[i+1][state(num(j)+k)] = k;
            }
        }
    }
    if (!dy[N][state(D)]){ puts("-1"); return 0; }
    for (i=N,k=state(D);i;i--){
        list.push_back(path[i][k]);
        if (i&1){
            k -= path[i][k];
        }else k += path[i][k];
    }
    for (i=list.size();i--;) printf("%d ",list[i]);
}