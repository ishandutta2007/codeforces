#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
int n,m,a[300010],K,l[300010],p[300010],rank[300010];
LL con,ans[300010],s[300010];
bool cmp(int i,int j)
{
    return p[i]<p[j];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    K=(int)sqrt(n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&l[i],&p[i]),rank[i]=i;
    sort(rank+1,rank+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int x=rank[i];
        if(p[x]>=K)
        {
            con=0;
            for(int j=l[x];j<=n;j+=p[x]) con+=a[j];
            ans[x]=con;
            continue;
        }
        if(p[x]>p[rank[i-1]])
        {
            for(int j=n;j>=1;j--)
            {
                if(j+p[x]>n) s[j]=a[j];
                else s[j]=s[j+p[x]]+a[j];
            }
        }
        ans[x]=s[l[x]];
    }
    for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
    return 0;
}