#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,K,a[200005],b[200005],id[200005],rs[200005];vector<int>v[200005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),v[i].clear();
	for(int i=1;i<=n;i++) v[a[i]].push_back(i),id[i]=i,rs[i]=0;
	sort(id+1,id+n+1,[](int x,int y){return v[x].size()>v[y].size();});
	vector<int>rst;for(int i=1;i<=n;i++)
		if((int)v[id[i]].size()>=K) for(int j=0;j<K;j++) rs[v[id[i]][j]]=j+1;
		else for(auto x:v[id[i]]) rst.push_back(x);
	int cnt=(int)rst.size()/K;for(int i=0;i<cnt;i++)
		for(int j=i*K;j<(i+1)*K;j++) rs[rst[j]]=j%K+1;
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}