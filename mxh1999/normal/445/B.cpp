#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 51
int f[maxn];
int n,m,sum;

int fa(int t)
{
    if (f[t]==t) return t;
    return f[t]=fa(f[t]);
}
void Union(int x,int y)
{
    int i=fa(x),j=fa(y);
    if (i!=j)   f[i]=j,sum--;;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)  f[i]=i;
    sum=n;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Union(x,y);
    }
    long long ans=1;
    for (int i=1;i<=n-sum;i++)  ans*=2;
    //ans=1<<(n-sum);
    cout<<ans<<endl;
    return 0;
}