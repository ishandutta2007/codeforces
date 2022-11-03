#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5005;
int n,cnt,a[maxn],ans[maxn],now[maxn],b[maxn],c[maxn],d[maxn];
bool vis[maxn];
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("? %d %d\n",i,0);
        fflush(stdout);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("? %d %d\n",b[i]=rand()%n,c[i]=rand()%n);
        fflush(stdout);
        scanf("%d",&d[i]);
    }
    cnt=0;
    for(i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(j=0;j<n;j++)
        {
            now[j]=i^a[j];
            if(now[j]<0 || now[j]>=n) break;
            if(vis[now[j]]) break;
            vis[now[j]]=true;
        }
        if(j<n) continue;
        if(now[i]) continue;
        for(j=0;j<n;j++)
            if(now[d[j]^now[b[j]]]!=c[j])
                break;
        if(j<n) continue;
        cnt++;
        if(cnt==1)
            memcpy(ans,now,sizeof(now));
    }
    printf("!\n%d\n%d",cnt,ans[0]);
    for(i=1;i<n;i++)
        printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}