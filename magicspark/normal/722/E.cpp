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
int n,m,k,s,fact[200005],inv[200005];
int r[2005],c[2005],id[2005];
bool cmp(int x,int y){return r[x]+c[x]<r[y]+c[y];}
int f[2005][25];
int get_nxt(int x){
	if(x==24)return 23;
	else return x+1;
}
int C(int nn,int mm){return 1ll*fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;}
int main(){
	fact[0]=1;
	for(int i=1;i<=2e5;i++)fact[i]=1ll*fact[i-1]*i%mod;
	inv[200000]=modpow(fact[200000],mod-2);
	for(int i=2e5-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	ios::sync_with_stdio();
	cin>>n>>m>>k>>s;
	for(int i=1;i<=k;i++)cin>>r[i]>>c[i],id[i]=i;
	sort(id+1,id+k+1,cmp);
	id[0]=0;id[k+1]=k+1;
	r[0]=1;c[0]=1;
	r[k+1]=n;c[k+1]=m;
	f[0][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<i;j++){
			int x=id[i],y=id[j];
//			cerr<<r[x]<<" "<<r[y]<<" "<<c[x]<<" "<<c[y]<<endl;
			if(r[y]<=r[x]&&c[y]<=c[x]){
				for(int j=0;j<25;j++){
					int nj=(i==k+1?j:get_nxt(j));
					f[x][nj]=(f[x][nj]+1ll*f[y][j]*C(r[x]-r[y]+c[x]-c[y],r[x]-r[y]))%mod;
				}
			}
		}
		for(int j=1;j<24;j++)f[id[i]][j]=(f[id[i]][j]-f[id[i]][j+1]+mod)%mod;
		for(int j=0;j<25;j++)cerr<<f[id[i]][j]<<" ";cerr<<endl;
	}
	vector<int>ways;
	for(int i=0;i<25;i++)ways.push_back(0);
	for(int i=1;i<=k;i++){
		for(int j=0;j<25;j++){
			ways[j]=(ways[j]+1ll*f[i][j]*C(n-r[i]+m-c[i],n-r[i]))%mod;
		}
	}
//	for(int i=0;i<25;i++)cerr<<i<<" "<<ways[i]<<endl; 
	ways[0]=C(n-1+m-1,n-1);
	for(int j=0;j<24;j++)ways[j]=(ways[j]-ways[j+1]+mod)%mod;
	int ans=0,sum=0;
	for(int i=24;i>=0;i--){
//		cerr<<i<<" "<<ways[i]<<endl;
		int cur=s;
		for(int j=1;j<=i;j++)cur=(cur+1)/2;
		ans=(ans+1ll*cur*ways[i])%mod;
	}
	cout<<1ll*ans*modpow(C(n-1+m-1,n-1),mod-2)%mod<<endl;
	return 0;
}