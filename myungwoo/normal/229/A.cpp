#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,ans=1e9;
int A[101][10004],L[101][10004],R[101][10004];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k,s;
    char ch;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=0;j<M;j++) scanf(" %c",&ch), A[i][j] = ch-'0';
    for (i=1;i<=N;i++){
        k = 1e9;
        for (j=0;j<M+M;j++){
            if (A[i][j%M]) k = 0;
            else k++;
            L[i][j%M] = k;
        }
        if (k >= 1e9) break;
        k = 1e9;
        for (j=M+M;j--;){
            if (A[i][j%M]) k = 0;
            else k++;
            R[i][j%M] = k;
        }
    }
    if (i <= N){ puts("-1"); return 0; }
    for (i=0;i<M;i++){
        s = 0;
        for (j=1;j<=N;j++) s += min(L[j][i],R[j][i]);
        if (ans > s)
            ans = s;
    }
    printf("%d",ans);
}