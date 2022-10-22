#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
template<class T>inline bool clmin(T &u,const T &v){return u>v?u=v,1:0;}
template<class T>inline bool clmax(T &u,const T &v){return u<v?u=v,1:0;}
template<class T>inline void clear(T *arr,int cnt,int val=0){memset(arr,val,sizeof(T)*(cnt+1));}
vector<int>e[110];
int dis[110][110];
set<int>pts[10010];
int a[10010],par[10010],cnt[10010],m,n,t_case;
string stat[110][110];
inline void solve(){
	auto id=[&](int u,int v){if(u>v)swap(u,v);return (u-1)*n+v;};
	function<int(int)>getf=[&](int l){return l==par[l]?l:par[l]=getf(par[l]);};
	auto join=[&](int u,int v){
		u=getf(u),v=getf(v);
		if(pts[u].size()>pts[v].size())swap(u,v);
		if(u!=v)par[u]=v,cnt[v]+=cnt[u],pts[v].insert(pts[u].begin(),pts[u].end());
	};
	for(ri i=1;i<n;++i)
		for(ri k=i+1;k<=n;++k){
			cin>>stat[i][k];
			for(ri l=1;l<=n;++l)
				if(stat[i][k][l-1]-'0')
					join(id(i,l),id(k,l));
		}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=n;++j)
			if(i!=j&&par[id(i,j)]==id(i,j)&&cnt[id(i,j)]==n-1&&pts[id(i,j)].size()==n){
				for(ri k=1;k<=n;++k)e[k].clear();
				for(ri k=1;k<n;++k)
					for(ri l=k+1;l<=n;++l)
						if(k!=l&&getf(id(k,l))==id(i,j))
							e[k].push_back(l),e[l].push_back(k);
				function<void(int,int,int*)>dfs=[&](int p,int f,int *d){
					d[p]=d[f]+1;
					for(ri i:e[p])if(i!=f)dfs(i,p,d);
				};
				for(ri k=1;k<=n;++k)dfs(k,0,dis[k]);
				for(ri i=1;i<n;++i)
					for(ri k=i+1;k<=n;++k)
						for(ri l=1;l<=n;++l)
							if((dis[i][l]==dis[k][l])!=(stat[i][k][l-1]-'0'))
								goto fail;
				cout<<"YES"<<endl;
				for(ri k=1;k<n;++k)
					for(ri l=k+1;l<=n;++l)
						if(k!=l&&getf(id(k,l))==id(i,j))
							cout<<k<<" "<<l<<endl;
				return;
				fail:;
			}
	cout<<"NO"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t_case;
	while(t_case--){
		cin>>n;
		for(ri i=1;i<=n*n;++i){
			par[i]=i,pts[i].clear(),cnt[i]=1;
			pts[i].insert((i-1)/n+1),pts[i].insert((i-1)%n+1);
		}
		solve();
	}
	return 0;
}