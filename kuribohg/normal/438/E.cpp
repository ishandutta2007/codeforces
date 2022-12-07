#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300010;
const int MOD=998244353;
const int INV_2=499122177;
const int g=3;
int n,m,c[MAXN],K=1,w[2][MAXN],A[MAXN],A0[MAXN],B[MAXN],tmp[MAXN];
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
    int step=qpow(g,(MOD-1)/k,MOD),inv_k=qpow(k,MOD-2,MOD),i,j,l,tmp;
    w[0][0]=w[1][k]=1;
    for(int i=1;i<=k;i++) w[0][i]=w[1][k-i]=((LL)w[0][i-1]*step)%MOD;
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
        for(int i=0;i<k;i++)
            x[i]=((LL)x[i]*inv_k)%MOD;
    }
}
void GetInv(int A[],int A0[],int k)
{
    if(k==1) {A0[0]=qpow(A[0],MOD-2,MOD),A0[1]=0;return;}
    GetInv(A,A0,k>>1);
    for(int i=0;i<k;i++) tmp[i]=A[i];
    for(int i=k;i<(k<<1);i++) tmp[i]=A0[i]=0;
    FFT(tmp,k<<1,0),FFT(A0,k<<1,0);
    for(int i=0;i<(k<<1);i++) A0[i]=((LL)A0[i]*((2LL-(((LL)tmp[i]*A0[i])%MOD)+MOD)%MOD))%MOD;
    FFT(A0,k<<1,1);
    for(int i=k;i<(k<<1);i++) A0[i]=0;
}
void GetSqrt(int A[],int A0[],int k)
{
    if(k==1) {A0[0]=1,A0[1]=0;return;}
    GetSqrt(A,A0,k>>1);
    GetInv(A0,B,k);
    for(int i=0;i<k;i++) tmp[i]=A[i];
    for(int i=k;i<(k<<1);i++) tmp[i]=A0[i]=0;
    FFT(tmp,k<<1,0),FFT(A0,k<<1,0),FFT(B,k<<1,0);
    for(int i=0;i<(k<<1);i++) A0[i]=(((LL)INV_2*A0[i])+((((LL)INV_2*tmp[i])%MOD)*B[i])%MOD)%MOD;
    FFT(A0,k<<1,1);
    for(int i=k;i<(k<<1);i++) A0[i]=0;
}
int main()
{
    scanf("%d%d",&n,&m);
    while(K<=m) K<<=1;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) A[c[i]]=MOD-4;
    A[0]=1;
    GetSqrt(A,A0,K);
    for(int i=0;i<K;i++) A[i]=A0[i],A0[i]=0;
    A[0]=(A[0]+1)%MOD;
    GetInv(A,A0,K);
    for(int i=0;i<K;i++) A0[i]=(A0[i]+A0[i])%MOD;
    for(int i=1;i<=m;i++) printf("%d\n",A0[i]);
    return 0;
}