#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
#include<queue>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAXN=200010;
int L,R,mid,ans[MAXN];
int n,m,a[MAXN],p[MAXN],b[MAXN],id[MAXN],tmpb[MAXN];
LL S,c[MAXN],cc[MAXN];
priority_queue<LL,vector<LL>,greater<LL> > q;
priority_queue<PLI,vector<PLI>,greater<PLI> > Q;
bool cmp(int i,int j)
{
    return b[i]>b[j];
}
bool cmp_2(int i,int j)
{
    return a[i]>a[j];
}
int main()
{
    scanf("%d%d%I64d",&n,&m,&S);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]),p[i]=i;
    sort(p+1,p+m+1,cmp_2);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),id[i]=i;
    for(int i=1;i<=n;i++) scanf("%I64d",&cc[i]);
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++) c[i]=cc[id[i]];
    sort(a+1,a+m+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    bool ok=false;
    for(int i=1;i<=n;i++)
        if(c[i]<=S&&b[i]>=a[1]) ok=true;
    if(!ok) {puts("NO");return 0;}
    L=1,R=m,mid;
    while(L<R)
    {
        mid=(L+R)>>1;
        int p=1,now=1;
        LL con=0;
        while(!q.empty()) q.pop();
        for(int i=1;i<=m;i+=mid)
        {
            while(now<=n&&b[now]>=a[i]) q.push(c[now]),now++;
            if(q.empty()) {con=2000000000;break;}
            con+=q.top();
            q.pop();
        }   
        if(con<=S) R=mid;
        else L=mid+1;
    }
    int cur=1,now=1;
    puts("YES");
    for(int i=1;i<=m;i+=L)
    {
        while(now<=n&&b[now]>=a[i]) Q.push(make_pair(c[now],id[now])),now++;
        int x=Q.top().second;Q.pop();
        for(int j=i;j<i+L;j++) ans[p[j]]=x;
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}