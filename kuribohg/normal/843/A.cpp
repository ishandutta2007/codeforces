#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],p[MAXN];
bool used[MAXN];
vector<int> ans[MAXN];
int tot;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=a[i];
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            int now=i;
            ++tot;
            while(!used[now])
            {
                used[now]=true;
                ans[tot].push_back(now);
                now=a[now];
            }
        }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}