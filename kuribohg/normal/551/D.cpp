#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,k,F,pow_2,ans;
int L,MOD,bit[70],cur;
LL qpow(LL x,LL n)
{
    LL con=1,p=x;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
struct Matrix
{
    int r,c;
    LL a[3][3];
    Matrix(){r=c=0;memset(a,0,sizeof(a));}
}A;
Matrix mul(const Matrix &p,const Matrix &q)
{
    Matrix con;
    con.r=p.r,con.c=q.c;
    for(int i=1;i<=p.r;i++)
        for(int j=1;j<=q.c;j++)
            for(int k=1;k<=p.c;k++)
                con.a[i][j]=(con.a[i][j]+p.a[i][k]*q.a[k][j])%MOD;
    return con;
}
Matrix qpow(const Matrix &x,LL n)
{
    n--;
    Matrix con=x,p=x;
    while(n)
    {
        if(n&1) con=mul(con,p);
        p=mul(p,p);
        n>>=1;
    }
    return con;
}
int main()
{
    scanf("%I64d%I64d%d%d",&n,&k,&L,&MOD);
    while(k)
    {
        if(k&1) bit[cur++]=1;
        else bit[cur++]=0;
        k>>=1;
    }
    if(cur>L) {puts("0");return 0;}
    A.r=2,A.c=2;
    A.a[1][1]=A.a[1][2]=A.a[2][1]=1;
    A=qpow(A,n+1);
    F=A.a[1][1];
    pow_2=qpow(2LL,n);
    ans=1;
    for(int i=0;i<L;i++)
    {
        if(bit[i]) ans=(ans*(pow_2-F+MOD))%MOD;
        else ans=(ans*F)%MOD;
    }
    printf("%I64d\n",ans%MOD);
    return 0;
}