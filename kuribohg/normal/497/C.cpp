#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
#include<map>
#include<iterator>
using namespace std;
const int MAXN=200010;
multimap<int,int> M;
multimap<int,int>::iterator it;
struct Node
{
    int l,r,k,sub;
    friend bool operator<(const Node &i,const Node &j){return i.l<j.l;}
}q[MAXN],p[MAXN];
int n,m,now,ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].l,&p[i].r),p[i].k=i;
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k),q[i].sub=i;
    sort(p+1,p+n+1);
    sort(q+1,q+m+1);
    for(int i=1;i<=n;i++)
    {
        while(now<m&&q[now+1].l<=p[i].l) M.insert(make_pair(q[now+1].r,now+1)),now++;
        it=M.lower_bound(p[i].r);
        while(it!=M.end()&&q[it->second].k==0) M.erase(it),it=M.lower_bound(p[i].r);
        if(it==M.end()) {puts("NO");return 0;}
        else ans[p[i].k]=q[it->second].sub,q[it->second].k--;
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}