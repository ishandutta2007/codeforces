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
const int N=200005;int n,m,K,dg[N],fg[N];unordered_set<int>e[N];
inline bool chk(int x)
{
	vector<int>v;for(auto y:e[x]) v.push_back(y);
	for(auto y:e[x]) if((int)e[y].size()<K-1) return 0;
	else for(auto z:v) if(y!=z&&e[y].find(z)==e[y].end()) return 0;
	printf("2\n%d",x);for(auto y:v) printf(" %d",y);
	return putchar('\n'),1;
}
inline void solve()
{
	read(n,m,K);for(int i=1;i<=n;i++) dg[i]=0,e[i].clear(),fg[i]=0;
	for(int i=1,x,y;i<=m;i++) read(x,y),e[x].insert(y),e[y].insert(x),dg[x]++,dg[y]++;
	queue<int>q;for(int i=1;i<=n;i++) if(dg[i]<K) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();if(fg[x]) continue;else fg[x]=1;
		if(1ll*K*(K-1)/2<=m&&dg[x]==K-1&&chk(x)) return;
		for(auto y:e[x]) {e[y].erase(x),m--;if(--dg[y]<K) q.push(y);}
		e[x].clear(),dg[x]=0;
	}int cnt=n;for(int i=1;i<=n;i++) cnt-=fg[i];
	if(cnt==0) return puts("-1"),void();else printf("1 %d\n",cnt);
	for(int i=1;i<=n;i++) if(!fg[i]) printf("%d ",i);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}