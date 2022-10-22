#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,a[N];ll ans;
ll W1(int x,int y)
{
	int t1=x/y,t2=x%y;
	return 1ll*t1*t1*(y-t2)+1ll*(t1+1)*(t1+1)*t2;
}
ll W2(int x,int y) {return W1(x,y)-W1(x,y+1);}
struct Node
{	
	int x,y;ll vl;
	bool operator < (Node t) const {return vl<t.vl;} 
};priority_queue<Node> q;
int main()
{
	scanf("%d %d",&n,&m);m-=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);ans+=1ll*a[i]*a[i];
		q.push((Node) {a[i],1,W2(a[i],1)});
	}
	for(int i=1;i<=m;++i)
	{
		Node t=q.top();q.pop();ans-=t.vl;
		q.push((Node) {t.x,t.y+1,W2(t.x,t.y+1)});
	}printf("%lld\n",ans);return 0;
}