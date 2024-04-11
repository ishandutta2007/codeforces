/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
struct base{
	int f[5];
	base(){memset(f,0,sizeof f);}
	base operator=(base y){
		for(int i=0;i<5;i++)f[i]=y.f[i];
		return *this;
	}
	bool insert(int x){
		for(int i=4;i>=0;i--)if(x&(1<<i)){
			if(f[i]==0){
				f[i]=x;
				for(int j=i-1;j>=0;j--)if(f[i]&(1<<j))f[i]^=f[j];
				for(int j=i+1;j<=4;j++)if(f[j]&(1<<i))f[j]^=f[i];
				return true;
			}else x^=f[i];
		}
		return false;
	}
	int get_id(){return f[4]*1024+f[3]*64+f[2]*8+f[1]*2+f[0];}
};
int bel[1<<16],tot;
base f[405];
void dfs(base x){
	if(bel[x.get_id()])return;
	f[tot]=x;bel[x.get_id()]=tot++;
	for(int i=1;i<=31;i++){
		auto y=x;
		if(y.insert(i))dfs(y);
	}
}
int n,m;
vector<pair<int,int> >g[100005];
vector<pair<int,int> >v;
int vis[100005],dep[100005],col[100005],cnt;
vector<base>all;
vector<pair<int,int> >buc[100005];
base b;
int cc,ord[100005];
bool hv[100005];
void go(int x,int par){
	vis[x]=1;col[x]=cnt;ord[x]=++cc;
	for(auto p:g[x])if(p.first!=par){
		int to=p.first,cost=p.second;
		if(vis[to]){
//			if(ord[to]<ord[x])cerr<<cnt<<" "<<(dep[to]^dep[x]^p.second)<<endl;
			if(ord[to]<ord[x])if(!b.insert(dep[to]^dep[x]^p.second))hv[cnt]=1;
			continue;
		}else{
			dep[to]=dep[x]^p.second;
			go(to,x);
		}
	}
}
int dp[375],tdp[375];
bool merge(base &x,base y){
	for(int i=0;i<=4;i++)if(y.f[i]){
//		cerr<<"show: "<<y.f[i]<<" "<<x.f[i]<<endl;
		if(!x.insert(y.f[i]))return false;
	}
	return true;
}
int main(){
	dfs(base());
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		if(x>y)swap(x,y);
		if(x==1){
			v.push_back(make_pair(y,z));
			continue;
		}
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	cnt=0;
	for(int i=2;i<=n;i++)if(!vis[i]){
		b=base();go(i,0);all.push_back(b);cnt++;
	}
	for(auto p:v){
		int to=p.first,cost=p.second;
//		cerr<<to<<" "<<col[to]<<endl;
		buc[col[to]].push_back(make_pair(to,cost));
	}
	dp[bel[base().get_id()]]=1;
	for(int i=0;i<cnt;i++){
		if(buc[i].size()>2)assert(0);
		if(hv[i]||buc[i].size()==0)continue;
//		cerr<<i<<" "<<buc[i].size()<<endl;
//		for(auto p:buc[i])cerr<<p.first<<" "<<p.second<<endl;
		memcpy(tdp,dp,sizeof tdp);
		if(buc[i].size()==2){
			for(int j=0;j<tot;j++)if(dp[j]){
				auto tmp=f[j];
				if(merge(tmp,all[i])){
					(tdp[bel[tmp.get_id()]]+=2ll*dp[j]%mod)%=mod;
				}
			}
			if(all[i].insert(dep[buc[i][0].first]^dep[buc[i][1].first]^buc[i][0].second^buc[i][1].second))for(int j=0;j<tot;j++)if(dp[j]){
				auto tmp=f[j];
				if(merge(tmp,all[i])){
					(tdp[bel[tmp.get_id()]]+=dp[j])%=mod;
				}
			}
		}else{
			for(int j=0;j<tot;j++)if(dp[j]){
				auto tmp=f[j];
				if(merge(tmp,all[i]))(tdp[bel[tmp.get_id()]]+=dp[j])%=mod;
			}
		}
		memcpy(dp,tdp,sizeof dp);
//		for(int j=0;j<tot;j++)if(dp[j])cerr<<i<<" "<<j<<" "<<dp[j]<<endl;
	}
	int ans=0;
	for(int i=0;i<tot;i++)(ans+=dp[i])%=mod;
	cout<<ans<<endl;
	return 0;
}