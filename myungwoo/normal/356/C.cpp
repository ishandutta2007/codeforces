#include <stdio.h>
#include <algorithm>
using namespace std;

int N,C[5],V[5],ans=2e9,sum;

int main()
{
    int i,j,k,n,need,move,support;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",&k), C[k]++, sum += k;
    for (i=0;i<N;i++){
        move = need = support = 0;
        for (j=k=0;j<5;j++){
            n = min(C[j],i-k);
            k += n;
            move += n*j;
            V[j] = C[j]-n;
        }
        if ((N-i)*4 < sum) break;
        support = V[4]+move;
        for (j=0;j<3;j++) need += V[j]*(3-j);
        if (need > support) continue;
        ans = min(ans,max(move,need));
    }
    printf("%d\n",ans==2e9?-1:ans);
}