#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int N,n;
double p[110];
struct Matrix
{
    int n,m;
    double a[129][129];
    Matrix()
    {
        n=0,m=0;
        memset(a,0,sizeof(a));
    }
}A,b;
Matrix mul(const Matrix &p,const Matrix &q)
{
    Matrix con;
    con.n=p.n,con.m=q.m;
    for(int i=1;i<=con.n;i++)
        for(int j=1;j<=con.m;j++)
            for(int k=1;k<=p.m;k++)
                con.a[i][j]+=p.a[i][k]*q.a[k][j];
    return con;
}
Matrix qpow(const Matrix &x,int n)
{
    Matrix con=x,p=x;
    n--;
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
    scanf("%d%d",&N,&n);
    for(int i=0;i<=n;i++) scanf("%lf",&p[i]);
    A.n=128,A.m=128;
    b.n=128,b.m=1;
    b.a[1][1]=1;
    for(int i=0;i<128;i++)
        for(int j=0;j<=n;j++)
            A.a[i+1][(i^j)+1]=p[j];
    b=mul(qpow(A,N),b);
    printf("%lf\n",1-b.a[1][1]);
    return 0;
}