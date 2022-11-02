#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 70004
#define bit(v,b) (((v)>>(b))&1)
#define dy(n) bit(D[(n)>>5],(n)&31)
typedef long long lld;

int N,S,path[MAXN],inside[MAXN],balls[MAXN],real_balls[MAXN];
bool chk[MAXN];
unsigned D[3000],E[3000];

struct Z{
    int balls,idx;
    bool operator < (const Z &ot)const{
        return balls>ot.balls;
    }
} A[MAXN];

int main()
{
    int i,j,k,sum=0,next;
    scanf("%d%d",&N,&S);
    for (i=1;i<=N;i++) scanf("%d",&A[i].balls), A[i].idx = i, balls[i] = A[i].balls;
    sort(A+1,A+N+1);
    if (A[1].balls > S){ puts("-1"); return 0; }
    D[A[1].balls>>5] |= 1<<(A[1].balls&31); path[A[1].balls] = 1;
    E[A[1].balls>>5] |= 1<<(A[1].balls&31);
    for (i=2,sum=A[1].balls;i<=N;i++){
        if (sum+A[i].balls > S) sum = S;
        else sum += A[i].balls;
        for (j=(sum-A[i].balls)>>5;j>=0;j--){
            E[j+(A[i].balls>>5)] |= D[j]<<(A[i].balls&31);
            if (A[i].balls&31) E[j+(A[i].balls>>5)+1] |= D[j]>>(32-(A[i].balls&31));
        }
        for (j=0;j<=(sum>>5);j++) if (D[j]^E[j]){
            for (k=0;k<32;k++) if (bit(D[j],k)^bit(E[j],k)){
                if (((j<<5)|k) <= S) path[(j<<5)|k] = i;
            }
        }
        for (j=sum>>5;j>=0;j--) D[j] = E[j];
    }
    if (!dy(S)){ puts("-1"); return 0; }
    for (i=S;i;i-=A[path[i]].balls) chk[path[i]] = 1;
    for (i=N,k=0;i;i--){
        inside[A[i].idx] = A[k].idx;
        if (!chk[i]) k = i;
        else k = 0;
    }
    for (i=1;i<=N;i++){
        printf("%d %d ",balls[i]-balls[inside[i]],!!inside[i]);
        if (inside[i]) printf("%d",inside[i]);
        puts("");
    }
}