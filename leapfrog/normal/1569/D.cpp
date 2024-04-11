//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=300005;int n,m,K;
set<int>X,Y;int at;
struct node{int x,y;}a[N];
inline void solve()
{
	read(n,m,K),at=0,X.clear(),Y.clear();
	for(int i=1,x;i<=n;i++) read(x),X.insert(x);
	for(int i=1,y;i<=m;i++) read(y),Y.insert(y);
	for(int i=1;i<=K;i++)
	{
		int x,y;read(x,y);
		if(X.count(x)&&Y.count(y)) continue;
		a[++at]=(node){x,y};
	}ll rs=0;
	sort(a+1,a+at+1,[](node a,node b){return a.x<b.x;});
	//for(int i=1;i<=at;i++) printf("%d %d\n",a[i].x,a[i].y);
	for(int i=1;i<=at;i++) if(!X.count(a[i].x))
	{
		auto it=X.lower_bound(a[i].x);
		int r=i,ri=*it;while(r<=at&&a[r].x<ri) r++;
		map<int,int>mp;for(int j=i;j<r;j++) mp[a[j].y]++;
		for(auto x:mp) rs-=1ll*x.second*(x.second-1)/2;
		rs+=1ll*(r-i)*(r-i-1)/2,i=r-1;
	}
	sort(a+1,a+at+1,[](node a,node b){return a.y<b.y;});
	for(int i=1;i<=at;i++) if(!Y.count(a[i].y))
	{
		auto it=Y.lower_bound(a[i].y);
		int r=i,ri=*it;while(r<=at&&a[r].y<ri) r++;
		map<int,int>mp;for(int j=i;j<r;j++) mp[a[j].x]++;
		for(auto x:mp) rs-=1ll*x.second*(x.second-1)/2;
		rs+=1ll*(r-i)*(r-i-1)/2,i=r-1;
	}printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}