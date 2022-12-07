#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define LONG_LONG_MAX 9223372036854775807LL
#define LONG_LONG_MIN (-LONG_LONG_MAX-1)
using namespace std;
typedef long long LL;
priority_queue<LL> q;
int n,m,k;
LL a[1010][1010],sum1[1000010],sum2[1000010],p,sum[1010],ret,ans;
bool cmp(const LL &i,const LL &j){return i>j;}
int main()
{
    scanf("%d%d%d%I64d",&n,&m,&k,&p);
    ans=LONG_LONG_MIN;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i]+=a[i][j];
    for(int i=1;i<=n;i++) q.push(sum[i]);
    for(int i=1;i<=k;i++)
    {
        sum1[i]=q.top();q.pop();
        q.push(sum1[i]-m*p);
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) sum[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[j]+=a[i][j];
    for(int i=1;i<=m;i++) q.push(sum[i]);
    for(int i=1;i<=k;i++)
    {
        sum2[i]=q.top();q.pop();
        q.push(sum2[i]-n*p);
    }
    sort(sum1+1,sum1+k+1,cmp);
    sort(sum2+1,sum2+k+1,cmp);
    for(int i=1;i<=k;i++) sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
    for(LL i=0;i<=k;i++)
    {
        ret=sum1[i]+sum2[k-i]-(k-i)*i*p;
        ans=max(ans,ret);
    }
    printf("%I64d\n",ans);
    return 0;
}