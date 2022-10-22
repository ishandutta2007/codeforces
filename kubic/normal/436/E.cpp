#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
int n,m,vs[N],a[N][2];ll ans;
struct Node
{
	int x,w;bool fl;
	bool operator < (Node t) const {return w>t.w;}
};priority_queue<Node> q1,q2;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		q1.push((Node) {i,a[i][0],0});
		q2.push((Node) {i,a[i][1],0});a[i][1]-=a[i][0];
	}
	while(m--)
	{
		while(!q1.empty() && vs[q1.top().x]>q1.top().fl) q1.pop();
		while(!q2.empty() && vs[q2.top().x]>q2.top().fl) q2.pop();
		Node t1=q1.top(),t2;q1.pop();
		while(!q1.empty() && vs[q1.top().x]>q1.top().fl) q1.pop();
		if(m && !q1.empty() && !q2.empty())
		{
			t2=q2.top();
			if(t1.w+q1.top().w>t2.w) q1.push(t1),swap(t1,t2),q2.pop();
		}ans+=a[t1.x][vs[t1.x]++];
		if(vs[t1.x]<2) q1.push((Node) {t1.x,a[t1.x][1],1});
	}printf("%lld\n",ans);
	for(int i=1;i<=n;++i) printf("%d",vs[i]);return 0;
}