#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define ll long long
#define pb push_back
int n,m,c,h,z1[N],z2[N];ll ans;struct Node {int x,y;}a[N];vector<int> vc[N];
bool cmp(Node x,Node y) {return x.y<y.y;}
struct List
{
	int w;struct Point {int pr,sf;}pt[N];
	void clear()
	{
		pt[0]=(Point) {0,1};pt[c+1]=(Point) {c,c+1};
		for(int i=1;i<=c;++i) pt[i]=(Point) {i-1,i+1};
		for(int i=0;i<=c;++i) w+=(a[i+1].y-a[i].y)*(a[i+1].y-a[i].y-1)/2;
		for(int i=0;i<=c;++i) w+=(a[i+1].y-a[i].y)*(a[i].y-a[max(i-h+1,0)].y);
	}
	void dlt(int u)
	{
		for(int i=0,j=u;i<=h;++i,j=pt[j].pr) z1[i]=a[j].y;
		for(int i=0,j=u;i<=h;++i,j=pt[j].sf) z2[i]=a[j].y;
		for(int i=0;i<h;++i) w+=(z1[i]-z1[i+1])*(z2[h-i]-z2[h-i-1]);
		pt[pt[u].pr].sf=pt[u].sf;pt[pt[u].sf].pr=pt[u].pr;
	}
}LS,LS1; 
int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&h);ans=1ll*n*(n+1)*m*(m+1)/4;
	for(int i=1;i<=c;++i) scanf("%d %d",&a[i].x,&a[i].y);sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;++i) vc[a[i].x].pb(i);a[c+1].y=m+1;LS1.clear();
	for(int i=1;i<=n;++i)
	{
		LS=LS1;for(int j=n;j>=i;--j) {ans-=LS.w;for(auto k:vc[j]) LS.dlt(k);}
		for(auto j:vc[i]) LS1.dlt(j);
	}printf("%lld\n",ans);return 0;
}