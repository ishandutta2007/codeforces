#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,D;
vector<int>g[222222];
int cnt[222222];
int par[222222];
bool used[222222];
inline int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
int main(){
	for(int i=1;i<222222;i++)par[i]=i;
	scanf("%d%d%d",&n,&m,&D);
	for(int i=0;i<m;i++){
		int a,b;scanf("%d%d",&a,&b);
		g[a].push_back(b);g[b].push_back(a);
		cnt[a]++;cnt[b]++;
		if(a!=1&&b!=1)par[find(a)]=find(b);
	}
	int mx=0,pos=1;
	if(cnt[1]<D)return puts("NO")&0;
	vector<pair<int,int> >ans;
	for(int i=0;i<g[1].size();i++){int x=g[1][i];
		if(find(1)!=find(x)){
			used[i]=true;
			ans.push_back(make_pair(1,x));
			par[find(1)]=find(x);
		}
	}
	if(ans.size()>D)return puts("NO")&0;
	for(int i=1;i<222222;i++)par[i]=i;
	for(auto x:ans)par[find(x.first)]=x.second;
	cerr<<D<<" "<<ans.size()<<endl;
	for(int i=0;ans.size()<D;i++){
		if(used[i])continue;
		ans.push_back(make_pair(1,g[1][i]));
		par[find(g[1][i])]=find(1);
	}
	for(int i=2;i<=n;i++){
		for(auto x:g[i]){if(x==1)continue;
			if(find(i)!=find(x)){
				par[find(i)]=find(x);
				ans.push_back(make_pair(i,x));
			}
		}
	}
	for(int i=1;i<n;i++)if(find(i)!=find(i+1))return puts("NO")&0;
	puts("YES");
	for(auto x:ans)printf("%d %d\n",x.first,x.second);
	return 0;
}