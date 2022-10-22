#include<cstdio>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3e5+5;
int n,a[N],m;
map<int,int> cnt;
vector<int> tmp[N],G[N],lsh;
int tot,pos[N]; bool vis[N];
#define all(v) v.begin(),v.end()
int getid(int x) {return lower_bound(all(lsh),x)-lsh.begin();}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n>>m;
		cnt.clear(); lsh.clear();
		fr(i,0,n) G[i].clear(),tmp[i].clear();
		fr(i,1,n) cin>>a[i],++cnt[a[i]],lsh.push_back(a[i]);
		sort(all(lsh));
		lsh.erase(unique(all(lsh)),lsh.end());
		fr(i,1,m) {
			int u,v; cin>>u>>v;
			G[getid(u)].push_back(getid(v));
			G[getid(v)].push_back(getid(u));
		}
		for(auto p:cnt) tmp[p.second].push_back(getid(p.first));
		tot=0; fr(i,1,n) if(tmp[i].size()) pos[++tot]=i;
		assert(tot<=2*sqrt(n)+5);
		ll ans=0;
		fr(i,1,tot) rf(t1,tmp[pos[i]].size()-1,0) {
			for(auto x:G[tmp[pos[i]][t1]]) vis[x]=1;
			fr(j,i,tot) rf(t2,i==j?t1-1:tmp[pos[j]].size()-1,0)
				if(!vis[tmp[pos[j]][t2]]) {
					ans=max(ans,1ll*(lsh[tmp[pos[i]][t1]]+lsh[tmp[pos[j]][t2]])*(pos[i]+pos[j]));
					//cout<<ans<<' '<<lsh[tmp[pos[i]][t1]]<<' '<<lsh[tmp[pos[j]][t2]]<<endl;
					break;
				}
			for(auto x:G[tmp[pos[i]][t1]]) vis[x]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}