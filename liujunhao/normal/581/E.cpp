#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 200000
int e,s,n,m,st,q[4][MAXN+10];
typedef pair<int,int>pii;
pii a[MAXN*2+10],f[MAXN*2+10],ans[MAXN+10];
int main()
{
    int i,front[4],rear[4],j;
    memset(f,0xff,sizeof f);
    memset(ans,0xff,sizeof ans);
    scanf("%d%d%d%d",&e,&s,&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i].second,&a[i].first);
    for(i=1;i<=m;i++){
        scanf("%d",&a[i+n].first);
        a[i+n].second=3+i;
    }
    sort(a+1,a+n+m+1);
    for(i=1;i<=n+m;i++)
        if(a[i].first>e)
            break;
    if(a[i].first==e)
        i--;
    a[i].first=e,a[i].second=3;
    e=i;
    f[e]=make_pair(0,0);
    q[3][0]=e;
    front[3]=rear[3]=0;
    front[2]=front[1]=0;
    rear[2]=rear[1]=-1;
    for(i=e-1;i;i--){
        int t=0x7fffffff;
        while(front[3]<=rear[3]&&a[q[3][front[3]]].first-a[i].first>s)
            front[3]++;
        while(front[2]<=rear[2]&&a[q[2][front[2]]].first-a[i].first>s)
            front[2]++;
        while(front[1]<=rear[1]&&a[q[1][front[1]]].first-a[i].first>s)
            front[1]++;
        if(a[i].second>3){
            for(j=3;j>0;j--)
                if(front[j]<=rear[j]){
                    if(j==1)
                        ans[a[i].second-3]=make_pair(f[q[j][front[j]]].first-s+a[q[j][front[j]]].first-a[i].first,f[q[j][front[j]]].second);
                    else if(j==2)
                        ans[a[i].second-3]=make_pair(f[q[j][front[j]]].first,f[q[j][front[j]]].second-s+a[q[j][front[j]]].first-a[i].first);
                    else
                        ans[a[i].second-3]=make_pair(f[q[j][front[j]]].first,f[q[j][front[j]]].second);
                    break;
            }
            if(!i)
                ans[a[i].second]=make_pair(-1,-1);
            continue;
        }
        for(j=3;j>=a[i].second;j--)
            if(front[j]<=rear[j])
                t=min(t,q[j][rear[j]]);
        if(t==0x7fffffff)
            for(;j;j--)
                if(front[j]<=rear[j]){
                    t=q[j][front[j]];
                    break;
                }
        if(t==0x7fffffff)
            break;
        f[i]=f[t];
        if(a[t].second>=a[i].second){
            if(a[i].second==1)
                f[i].first+=a[t].first-a[i].first;
            else if(a[i].second==2)
                f[i].second+=a[t].first-a[i].first;
        }
        else{
            if(a[i].second==2){
                f[i].second+=s;
                f[i].first-=s-a[t].first+a[i].first;
            }
            else if(a[i].second==3){
                if(a[t].second==2)
                    f[i].second-=s-a[t].first+a[i].first;
                else
                    f[i].first-=s-a[t].first+a[i].first;
            }
        }
        q[a[i].second][++rear[a[i].second]]=i;
    }
    for(i=1;i<=m;i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
}