#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node
{
    int lb;
    LL cost;
    bool operator < (const struct node &p)const
    {return cost<p.cost;}
}a[300005];
priority_queue<node> q;
int n,k,ans[300005];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        a[i].lb=i;
        scanf("%lld",&a[i].cost);
    }
    for(int i=1;i<=k;i++)
        if(i<=n)q.push(a[i]);
    LL sum=0;
    for(int i=k+1;i<=k+n;i++)
    {
        if(i<=n)q.push(a[i]);
        node t=q.top();q.pop();
        ans[t.lb]=i;
        sum+=1ll*t.cost*(i-t.lb);
    }
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}