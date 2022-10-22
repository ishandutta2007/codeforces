#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,c,h,a[N],b[N];ll L,R,ans,d[N];
struct Node {int x;ll vl;bool operator < (Node t) const {return vl>t.vl;}};
priority_queue<Node> q; 
bool chk(ll x)
{
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;++i) if(a[i]+1ll*b[i]*m>x)
		q.push((Node) {i,x/b[i]}),d[i]=0;
	for(int i=1;i<=m;++i) for(int j=1;j<=c;++j)
	{
		if(q.empty()) return 1;
		Node t=q.top();q.pop();if(t.vl<i) return 0;d[t.x]+=h;
		if(a[t.x]+1ll*b[t.x]*m-d[t.x]>x)
			q.push((Node) {t.x,(x+d[t.x])/b[t.x]});
	}return q.empty();
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&h);
	for(int i=1;i<=n;++i)
		scanf("%d %d",&a[i],&b[i]),R=max(R,a[i]+1ll*b[i]*m);
	while(L<=R) {ll mid=(L+R)/2;if(chk(mid)) ans=mid,R=mid-1;else L=mid+1;}
	printf("%lld\n",ans);return 0;
}