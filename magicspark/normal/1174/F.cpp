#include<bits/stdc++.h>
#define ff fflush(stdout)
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,cur=1,deep;
vector<int>g[200005];
int dep[200005],sum[200005],Max[200005],p[200005],chain[200005];
void dfs(int x,int par=0,int depth=0){
	p[x]=par;dep[x]=depth;
	sum[x]=(dep[x]==deep?1:0);
	Max[x]=-inf;chain[x]=x;
	for(auto to:g[x])if(to!=par){
		dfs(to,x,depth+1);
		sum[x]+=sum[to];
		if(sum[to]>Max[x]){
			Max[x]=sum[to];
			chain[x]=chain[to];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout<<"d "<<1<<endl;
	ff;cin>>deep;
	if(deep==0){
		cout<<"! 1"<<endl;ff;
		return 0;
	}
	dfs(1);
	int limit=50;
	while(limit--){
		int tmp=chain[cur],len=dep[tmp];
		cout<<"d "<<tmp<<endl;ff;
		int v;cin>>v;
		int lca=(len+deep-v)>>1;
		for(int i=dep[cur];i<lca;i++){
			for(auto to:g[cur]){
				if(to!=p[cur]&&chain[cur]==chain[to]){
					cur=to;
					break;
				}
			}
		}
		if(dep[cur]==deep){
			cout<<"! "<<cur<<endl;ff;
			return 0;
		}
		cout<<"s "<<cur<<endl;
		ff;cin>>cur;
	}
	return 0;
}