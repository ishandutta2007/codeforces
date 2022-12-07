#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<ctime>
#include<queue>
#include<utility>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,k,Log[100010],a[10010],tot,p,con[100010],tot2;
bool used[100010];
inline int lowbit(int x)
{
    return x&(-x);
}
int main()
{
    scanf("%d%d",&n,&k);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    while(n>0)
    {
        if(n&1) a[++tot]=p;
        n>>=1,p++;
    }
    used[0]=true;
    for(int i=tot;i>=1;i--)
    {
        int ans=0;
        while(ans<=k&&used[ans])
        {
            if(a[i]==-1) {puts("-1");return 0;}
            else ans+=1<<a[i];
        }
        if(ans>k) {a[i+1]=a[i]-1,a[i]=a[i]-1,i+=2;continue;}
        con[++tot2]=ans,used[ans]=true;
    }
    printf("%d\n",tot2);
    for(int i=1;i<tot2;i++)
        printf("%d ",con[i]);;
    printf("%d\n",con[tot2]);
    return 0;
}