#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
vector<int>g[222222];
int cnt[222222];
int par[222222];
inline int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;scanf("%d%d",&a,&b);
		g[a].push_back(b);g[b].push_back(a);
		cnt[a]++;cnt[b]++;
	}
	int mx=0,pos=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]>mx){
			mx=cnt[i];pos=i;
		}
	}
	for(int i=1;i<222222;i++)par[i]=i;
	for(auto x:g[pos]){
		printf("%d %d\n",x,pos);
		if(find(pos)!=find(x)){
			par[find(pos)]=find(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto x:g[i]){
			if(find(i)!=find(x)){
				par[find(i)]=find(x);
				printf("%d %d\n",i,x);
			}
		}
	}
	return 0;
}