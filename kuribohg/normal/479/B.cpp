#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int n,m,sub1,sub2,a[110],tot,ans[1010][2];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        sub1=1,sub2=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>a[sub1]) sub1=i;
            if(a[i]<a[sub2]) sub2=i;
        }
        if(sub1==sub2) break;
        ans[++tot][0]=sub1,ans[tot][1]=sub2;
        a[sub1]--,a[sub2]++;
    }
    sub1=1,sub2=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[sub1]) sub1=i;
        if(a[i]<a[sub2]) sub2=i;
    }
    printf("%d %d\n",a[sub1]-a[sub2],tot);
    for(int i=1;i<=tot;i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}