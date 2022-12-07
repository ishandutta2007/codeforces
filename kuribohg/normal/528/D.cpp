#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=998244353;
const int g=3;
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
int w[2][2000010],step;
void initFFT(int k)
{
    step=qpow(g,(MOD-1)/k,MOD);
    w[0][0]=w[1][k]=1;
    for(int i=1;i<=k;i++) w[0][i]=w[1][k-i]=((LL)w[0][i-1]*step)%MOD;
}
void FFT(int x[],int k,int v)
{
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
                x[j+l+(i>>1)]=((LL)x[j+l]-tmp+MOD)%MOD;
                x[j+l]=((LL)x[j+l]+tmp)%MOD;
            }
    if(v)
    {
        int inv_k=qpow(k,MOD-2,MOD);
        for(int i=0;i<k;i++)
            x[i]=((LL)x[i]*inv_k)%MOD;
    }
}
int n,m,k,K,res;
int A[2000010],B[2000010],C[2000010],ans[300010];
char S[300010],T[300010];
void work(char ch)
{
    int tms=0;
    for(int i=0;i<k;i++) A[i]=0;
    for(int i=0;i<k;i++) B[i]=0;
    for(int i=0;i<n;i++)
    {
        if(S[i]!=ch) continue;
        int L=max(0,i-K),R=min(n-1,i+K);
        A[L]++,A[R+1]--;
    }
    for(int i=1;i<=n;i++) A[i]+=A[i-1];
    for(int i=0;i<n;i++) if(A[i]) A[i]=1;
    for(int i=0;i<m;i++) if(T[i]==ch) B[i]=1,tms++;
    reverse(B,B+m);
    k=1;
    while(k<=max(n,m)) k<<=1;
    k<<=1;
    initFFT(k);
    FFT(A,k,0),FFT(B,k,0);
    for(int i=0;i<k;i++) C[i]=((LL)A[i]*B[i])%MOD;
    FFT(C,k,1);
    for(int i=0;i<n;i++) if(C[i+m-1]==tms) ans[i]++;
}
int main()
{
    scanf("%d%d%d%s%s",&n,&m,&K,S,T);
    work('A');
    work('G');
    work('C');
    work('T');
    for(int i=0;i<n;i++) if(ans[i]==4) res++;
    printf("%d\n",res);
    return 0;
}