#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=5000010;
const int MOD=998244353;
const int g=3;
int n,m,k=1,a[MAXN],A[MAXN],B[MAXN],w[2][MAXN];
int ans[MAXN],tot;
int qpow(int x,int n,int MOD)
{
    int p=x,con=1;
    while(n)
    {
        if(n&1) con=((LL)con*p)%MOD;
        p=((LL)p*p)%MOD;
        n>>=1;
    }
    return con;
}
void FFT(int x[],int k,int v)
{
    int step=qpow(g,(MOD-1)/k,MOD);
    w[0][0]=w[1][k]=1;
    for(int i=1;i<=k;i++) w[0][i]=w[1][k-i]=((LL)w[0][i-1]*step)%MOD;
    int i,j,l,tmp;
    for(i=j=0;i<k;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(l=k>>1;(j^=l)<l;l>>=1);
    }
    for(i=2;i<=k;i<<=1)
        for(j=0;j<k;j+=i)
            for(l=0;l<(i>>1);l++)
            {
                tmp=((LL)x[j+l+(i>>1)]*w[v][k/i*l])%MOD;
                x[j+l+(i>>1)]=(x[j+l]-tmp+MOD)%MOD;
                x[j+l]=(x[j+l]+tmp)%MOD;
            }
    if(v)
    {
        int inv_k=qpow(k,MOD-2,MOD);
        for(int i=0;i<k;i++) x[i]=((LL)x[i]*inv_k)%MOD;
    }
}
int main()
{
    scanf("%d%d",&n,&m),m++;
    for(int i=1,x;i<=n;i++) scanf("%d",&x),A[x]=B[x]=1;
    for(int i=1;i<=m;i++)
        if(A[i]==1)
            for(int j=i+i;j<=m;j+=i)
                A[j]=2;
    while(k<=(m<<1)) k<<=1;
    FFT(A,k,0);
    for(int i=0;i<k;i++) A[i]=((LL)A[i]*A[i])%MOD;
    FFT(A,k,1);
    for(int i=0;i<k;i++) A[i]=(A[i]+B[i])%MOD;
    m--;
    for(int i=1;i<=m;i++) if(A[i]!=0&&B[i]==0) {puts("NO");return 0;}
    for(int i=1;i<=m;i++)
        if(A[i]==1) ans[++tot]=i;
    puts("YES");
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}