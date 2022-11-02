# include <iostream>
# include <cstdio>
using namespace std;
const int maxn=100010;

int a[maxn],n,m;
long long L,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m); L=a[1];
    int w,h;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&w,&h);
        ans=max(L,(long long)a[w]);
        printf("%I64d\n",ans);
        L=ans+h;
    }
    return 0;
}