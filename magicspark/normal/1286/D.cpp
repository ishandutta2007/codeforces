/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
inline int inv(int x){
	return modpow(x,mod-2,mod);
}
int n;
int x[100005],v[100005],p[100005];
int dat[100005];
struct event{
	int id,len,speed,p,l,r;
};
bool operator<(event a,event b){
	return a.len*b.speed<b.len*a.speed;
}
struct SGT{
	#define SIZE 131072
	int f[SIZE<<1][2][2],l[SIZE<<1],r[SIZE<<1],ban[SIZE][2][2],ql,qr;
	//0->left 1->right
	void pushup(int id){
		for(int i=0;i<2;i++)for(int j=0;j<2;j++)f[id][i][j]=0ll;
		if(l[id<<1|1]>n){
			memcpy(f[id],f[id<<1],sizeof f[id]);
			return;
		}
		for(int l1=0;l1<2;l1++){
			for(int r1=0;r1<2;r1++){
				for(int l2=0;l2<2;l2++){
					for(int r2=0;r2<2;r2++){
						int add=f[id<<1][l1][r1]*f[id<<1|1][l2][r2]%mod;
						if(!ban[r[id<<1]][r1][l2])f[id][l1][r2]=(f[id][l1][r2]+add)%mod;
					}
				}
			}
		}
	}
	void init(){
		memset(f,0,sizeof f);
		for(int i=SIZE;i<SIZE*2;i++){
			l[i]=r[i]=i-SIZE;
			if(i-SIZE<=n)f[i][0][0]=(1+mod-p[i-SIZE])%mod;
			if(i-SIZE<=n)f[i][1][1]=p[i-SIZE];
		}
		for(int i=SIZE-1;i>=1;i--)l[i]=l[i<<1],r[i]=r[i<<1|1];
		for(int i=SIZE-1;i>=1;i--)pushup(i);
	}
	void rec(int L,int R,int k){
		if(R<ql||qr<L)return;
		if(L==R)return;
		rec(L,(L+R)/2,k<<1);
		rec((L+R)/2+1,R,k<<1|1);
		pushup(k);
	}
	void set_ban(int a,int b,int c){
		ql=a;qr=a+1;
		ban[a][b][c]=1;
		rec(0,SIZE-1,1);
	}
	int get(){
		return (f[1][0][0]+f[1][0][1]+f[1][1][0]+f[1][1][1])%mod;
	}
}seg;
signed main(){
	cin>>n;
	const int inv100=inv(100); 
	for(int i=1;i<=n;i++){
		cin>>x[i]>>v[i]>>p[i];p[i]=p[i]*inv100%mod;
	}
	seg.init();
	vector<event>all;
	for(int i=1;i<n;i++){
		all.push_back((event){i,x[i+1]-x[i],v[i]+v[i+1],p[i]*(1+mod-p[i+1])%mod,1,0});
		if(v[i]>v[i+1]){
			all.push_back((event){i,x[i+1]-x[i],v[i]-v[i+1],p[i]*p[i+1]%mod,1,1});
		}
		if(v[i]<v[i+1]){
			all.push_back((event){i,x[i+1]-x[i],v[i+1]-v[i],(1+mod-p[i])*(1+mod-p[i+1])%mod,0,0});
		}
	}
	sort(all.begin(),all.end());
	int ans=0;
	for(auto e:all){
		int now=seg.get();
		seg.set_ban(e.id,e.l,e.r);
		int nxt=seg.get();
		ans+=(now-nxt+mod)*e.len%mod*inv(e.speed)%mod;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}