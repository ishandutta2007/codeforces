#include <stdio.h>
#include <algorithm>
using namespace std;

int N,M,A[5005],S[5005],ans=-1e9;
int D[5005][5005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k,mx;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i), S[i] = A[i]+S[i-1];
    for (i=1;i<=N;i++) for (j=i;j<=N;j++) D[i][j] = -1e9;
    for (i=1;i<=N;i++) D[1][i] = 1;
    for (i=1;i<N;i++){
        k = i; mx = -1e9;
        for (j=i+1;j<=N;j++){
            while (k && S[i]-S[k-1] <= S[j]-S[i]) mx = max(mx,D[k][i]), k--;
            D[i+1][j] = mx+1;
        }
    }
    for (i=1;i<=N;i++) if (ans < D[i][N]) ans = D[i][N];
    printf("%d",N-ans);
}