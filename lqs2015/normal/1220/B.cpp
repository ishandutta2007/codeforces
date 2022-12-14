#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
int n,a[1111][1111],d,ans[1111];
void check(int x)
{
    ans[1]=x;
    for (int i=2;i<=n;i++) ans[i]=a[1][i]/x;
    bool f=0;
    for (int i=2;i<n;i++) 
    {
        if (1ll*ans[i]*ans[i+1]==a[i][i+1]);
        else f=1;
    }
    if (!f)
    {
        for (int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
        exit(0);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=2;i<=n;i++) d=gcd(d,a[1][i]);
    int c=sqrt(d);
    for (int i=1;i<=c;i++)
    {
        if (d%i==0)
        {
            check(i);
            check(d/i);
        }
    }
    return 0;
}