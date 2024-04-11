//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
#define maxn 1010
int n,m;
int p[1010],q[1010],ans1[1010][1010],ans2[1010][1010];
ll t,tot;
double ans;
bool a[1010][1010];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            char ch=getchar();
            while (ch!='.' && ch!='X')  ch=getchar();
            if (ch=='X')    a[i][j]=true,p[i]=j,q[j]=i;;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            t=((ll)(i*(i-1)+(n-i+1)*(n-i))*m+(ll)(j*(j-1)+(m-j+1)*(m-j))*n)/2;
            if (a[i][j])    {ans-=t;continue;}
            if (i<q[j]) ans1[i][j]=2*n-2*q[j];else
                if (q[j] && i>q[j]) ans1[i][j]=2*q[j]-2;
            if (j<p[i]) ans2[i][j]=2*m-2*p[i];else
                if (p[i] && j>p[i]) ans2[i][j]=2*p[i]-2;
            ans+=t,tot++;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (q[j] && i>q[j])
        {
            if (q[j]>q[j-1] && q[j-1])  ans1[i][j]+=ans1[i-1][j-1];
            if (q[j]>q[j+1] && q[j+1])  ans1[i][j]+=ans1[i-1][j+1];
        }
    for (int i=n;i>=1;i--)
        for (int j=1;j<=m;j++)
        if (q[j] && i<q[j])
        {
            if (q[j]<q[j-1] && q[j-1])  ans1[i][j]+=ans1[i+1][j-1];
            if (q[j]<q[j+1] && q[j+1])  ans1[i][j]+=ans1[i+1][j+1];
        }
    for (int j=1;j<=m;j++)
        for (int i=1;i<=n;i++)
        if (p[i] && j>p[i])
        {
            if (p[i]>p[i-1] && p[i-1])  ans2[i][j]+=ans2[i-1][j-1];
            if (p[i]>p[i+1] && p[i+1])  ans2[i][j]+=ans2[i+1][j-1];
        }
    for (int j=m;j>=1;j--)
        for (int i=1;i<=n;i++)
        if (p[i] && j<p[i])
        {
            if (p[i]<p[i-1] && p[i-1])  ans2[i][j]+=ans2[i-1][j+1];
            if (p[i]<p[i+1] && p[i+1])  ans2[i][j]+=ans2[i+1][j+1];
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            ans+=ans1[i][j]+ans2[i][j];
    for (int i=1;i<n;i++)
    if (p[i])
        for (int j=i+1;j<=n;j++)
        if (p[j])
            ans+=((j-i)+abs((p[i]-p[j])))*2;
    printf("%.9lf\n",ans/(tot*tot));
    return 0;
}