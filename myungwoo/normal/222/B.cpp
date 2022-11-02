#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,Q;
int A[1001][1001],rnum[1001],cnum[1001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    int x,y;
    char ch;
    scanf("%d%d%d",&N,&M,&Q);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j);
    for (i=1;i<=N;i++) rnum[i] = i;
    for (i=1;i<=M;i++) cnum[i] = i;
    while (Q--){
        scanf(" %c%d%d",&ch,&x,&y);
        if (ch == 'r'){
            swap(rnum[x],rnum[y]);
        }else if (ch == 'c'){
            swap(cnum[x],cnum[y]);
        }else{
            printf("%d\n",A[rnum[x]][cnum[y]]);
        }
    }
}