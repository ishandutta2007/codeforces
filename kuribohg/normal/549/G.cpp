#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
const int MAXN=500010;
int n,a[MAXN],ans[MAXN],Max;
typedef pair<int,int> PII;
priority_queue<PII> q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) q.push(make_pair(a[i]-(n+1-i),i));
    for(int i=1;i<=n;i++)
    {
        PII tmp=q.top();q.pop();
        ans[n+1-i]=tmp.first+i;
    }
    for(int i=1;i<=n;i++)
    {
        if(Max>ans[i]) {puts(":(");return 0;}
        Max=max(Max,ans[i]);
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}