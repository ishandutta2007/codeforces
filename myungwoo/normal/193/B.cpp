#include <stdio.h>

typedef long long lld;

int N,U,R; lld ans=-1e16;
int A[32],B[32],K[32],P[32];

void proc()
{
    int i; lld v=0;
    for (i=1;i<=N;i++) v += A[i]*K[i];
    if (ans < v) ans = v;
}

void dfs(int n,int cnt_xor,bool chk)
{
    if ((U-n)%2 == 0) proc();
    if (n == U) return ;
    int i,tmp[32]={0,};
    for (i=1;i<=N;i++) tmp[i] = A[i];
    if (n-cnt_xor >= cnt_xor && !chk){
        for (i=1;i<=N;i++) A[i] ^= B[i];
        dfs(n+1,cnt_xor+1,1);
        for (i=1;i<=N;i++) A[i] = tmp[i];
    }
    for (i=1;i<=N;i++) A[i] = tmp[P[i]]+R;
    dfs(n+1,cnt_xor,0);
    for (i=1;i<=N;i++) A[i] = tmp[i];
}

int main()
{
    int i;
    scanf("%d%d%d",&N,&U,&R);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++) scanf("%d",B+i);
    for (i=1;i<=N;i++) scanf("%d",K+i);
    for (i=1;i<=N;i++) scanf("%d",P+i);
    dfs(0,0,0);
    printf("%I64d",ans);
}