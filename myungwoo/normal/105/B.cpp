#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))

int N,K,A,B,ps[9],L[9];
double ans,tar;

void proc(int n,int c,int sum,double pos)
{
    if (c > N/2){
        tar += pos;
        return;
    }
    if (n > N){
        tar += pos*double(A)/double(A+sum);
        return;
    }
    proc(n+1,c+1,sum,pos*(ps[n]/100.));
    proc(n+1,c,sum+L[n],pos*(1-(ps[n]/100.)));
}

void dfs(int n,int left)
{
    if (n == N){
        int tmp=ps[n];
        ps[n] = min(100,ps[n]+left*10);
        tar = 0;
        proc(1,0,0,1);
        if (ans < tar) ans = tar;
        ps[n] = tmp;
        return;
    }
    if (!left){
        tar = 0;
        proc(1,0,0,1);
        if (ans < tar) ans = tar;
        return;
    }
    if (ps[n] < 100 && left > 0){
        ps[n] += 10;
        dfs(n,left-1);
        ps[n] -= 10;
    }
    dfs(n+1,left);
}

int main()
{
    int i;
    scanf("%d%d%d",&N,&K,&A);
    for (i=1;i<=N;i++) scanf("%d%d",L+i,ps+i), B += L[i];
    dfs(1,K);
    printf("%.9lf",ans);
}