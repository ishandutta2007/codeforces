#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define pb push_back
int T,n,m,c,b[N];ll dp[N];struct Node {int x1,y1,x2,y2,w;}a[N];
struct Node1 {int id;bool fl;};vector<Node1> vc[N];
bool cmp(Node1 x,Node1 y) {return (x.fl?a[x.id].y2:a[x.id].y1)<(y.fl?a[y.id].y2:a[y.id].y1);}
void slv()
{
	scanf("%d %d %d",&n,&m,&c);c+=2;for(int i=1;i<=c;++i) dp[i]=1e18;
	for(int i=1;i<=n;++i) vc[i].clear(),scanf("%d",&b[i]);
	for(int i=1;i<c-1;++i)
	{
		scanf("%d %d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].w);
		vc[a[i].x1].pb((Node1) {i,0});vc[a[i].x2].pb((Node1) {i,1});
	}a[c-1]=(Node) {1,1,1,1,0};vc[1].pb((Node1) {c-1,1});
	a[c]=(Node) {n,m,n,m,0};vc[n].pb((Node1) {c,0});dp[c-1]=0;
	for(int i=1;i<=n;++i)
	{
		ll mn=1e18;sort(vc[i].begin(),vc[i].end(),cmp);
		for(auto j:vc[i]) if(j.fl) {if(dp[j.id]<1e18) mn=min(mn,dp[j.id]-1ll*b[i]*a[j.id].y2);}
		else if(mn<1e18) dp[j.id]=min(dp[j.id],mn+1ll*b[i]*a[j.id].y1-a[j.id].w);
		mn=1e18;reverse(vc[i].begin(),vc[i].end());
		for(auto j:vc[i]) if(j.fl) {if(dp[j.id]<1e18) mn=min(mn,dp[j.id]+1ll*b[i]*a[j.id].y2);}
		else if(mn<1e18) dp[j.id]=min(dp[j.id],mn-1ll*b[i]*a[j.id].y1-a[j.id].w);
	}if(dp[c]<1e18) printf("%lld\n",dp[c]);else puts("NO ESCAPE");
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}