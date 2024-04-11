#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct Node
{
    int x,sub;
}a[1010];
int n,m,ans[1010];
inline bool cmp(const Node &i,const Node &j)
{
    return i.x<j.x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].sub=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        ans[a[i].sub]=(i&1);
    for(int i=1;i<n;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}