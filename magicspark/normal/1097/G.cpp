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
#define int long long
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
int n,k,f[100005][205],S[405][405],sz[100005],pw[100005],ans[100005];
const int inv2=(mod+1)/2;
vector<int>g[100005];
void dfs(int x,int par){
	sz[x]=1;f[x][0]=1;
	for(auto to:g[x])if(to!=par){
		dfs(to,x);
		for(int j=min(k,sz[to]);j>=0;j--){
			int tmp=f[to][j];
			if(j==0)tmp=1ll*tmp*(mod+1-pw[sz[to]])%mod;
			ans[j+1]=(ans[j+1]+1ll*(mod+1-pw[n-sz[to]])*tmp)%mod;
//			ans[j]=(ans[j]+1ll*pw[n-sz[to]]*tmp)%mod;
			f[to][j+1]=(f[to][j+1]+tmp)%mod;
		}
		for(int i=min(sz[x],k);i>=0;i--){
			for(int j=1;j<=min(sz[to],k)&&i+j<=k;j++){
				f[x][i+j]=(f[x][i+j]+1ll*f[x][i]*f[to][j])%mod;
				if(i)ans[i+j]=(ans[i+j]+1ll*f[x][i]*f[to][j])%mod;
			}
		}
		sz[x]+=sz[to];
	}
//	for(int i=0;i<=sz[x];i++)if(f[x][i])cerr<<x<<" "<<i<<" "<<f[x][i]<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	S[0][0]=1;
	for(int i=1;i<=200;i++)for(int j=1;j<=i;j++)S[i][j]=(1ll*S[i-1][j]*j+S[i-1][j-1])%mod;
	pw[0]=1;for(int i=1;i<=1e5;i++)pw[i]=1ll*pw[i-1]*inv2%mod;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	int fans=0,mul=1;
//	for(int i=0;i<=k;i++)cerr<<ans[i]<<" ";cerr<<endl;
	for(int i=0;i<=k;i++){
		fans=(fans+1ll*S[k][i]*ans[i]%mod*mul)%mod;
		mul=1ll*mul*(i+1)%mod;
	}
	for(int i=1;i<=n;i++)fans=2ll*fans%mod;
	cout<<fans<<endl;
	return 0;
}