#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 300005

int N,P,RT,W[MAXN];
__int64 S[MAXN],K[MAXN];

struct Z{
    int a,b,idx;
    bool operator < (const Z &ot)const{
        return b<ot.b;
    }
} A[MAXN];

int main()
{
    int i,j;
    scanf("%d",&N);
    for (RT=1;RT*RT<N;RT++);
    for (i=1;i<=N;i++) scanf("%d",W+i);
    scanf("%d",&P);
    for (i=1;i<=P;i++) scanf("%d%d",&A[i].a,&A[i].b), A[i].idx = i;
    sort(A+1,A+P+1);
    for (i=1;i<=P&&A[i].b<RT;i++){
        if (A[i].b != A[i-1].b){
            for (j=N;j>0;j--){
                if (j+A[i].b > N) S[j] = W[j];
                else S[j] = W[j]+S[j+A[i].b];
            }
        }
        K[A[i].idx] = S[A[i].a];
    }
    for (;i<=P;i++){
        for (j=A[i].a;j<=N;j+=A[i].b) K[A[i].idx] += W[j];
    }
    for (i=1;i<=P;i++) printf("%I64d\n",K[i]);
}