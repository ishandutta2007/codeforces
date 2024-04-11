#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const long long MOD=1000000007;
struct Matrix
{
    long long a[3][3];
    Matrix(){memset(a,0,sizeof(a));}
}A;
Matrix mul(const Matrix &p,const Matrix &q)
{
    Matrix con;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                con.a[i][j]=(con.a[i][j]+p.a[i][k]*q.a[k][j])%MOD;
    return con;
}
Matrix qpow(const Matrix &x,long long n)
{
    Matrix p,w=x;
    p.a[1][1]=p.a[2][2]=1;
    while(n>0)
    {
        if(n&1) p=mul(p,w);
        w=mul(w,w);
        n>>=1;
    }
    return p;
}
long long x,y,n;
int main()
{
    scanf("%I64d%I64d%I64d",&x,&y,&n);
    A.a[1][1]=1,A.a[2][1]=-1,A.a[1][2]=1,A.a[2][2]=0;
    A=qpow(A,n-2);
    x=(x+MOD)%MOD;
    y=(y+MOD)%MOD;
    if(n==1) printf("%I64d\n",x);
    else if(n==2) printf("%I64d\n",y);
    else printf("%I64d\n",((y*A.a[1][1]%MOD)+(x*A.a[2][1]%MOD)+MOD)%MOD);
    return 0;
}