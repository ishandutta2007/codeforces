/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
inline int Rand(){return rand()*32768+rand();}
const int md1=9000000000000000041ll;
const int md2=9000000000000000053ll;
int n,q,b[62],r[62];
vector<int>B[62],R[62];
int mat[62][62];
int a[62][62],ans[62];
int f1[62],f2[62];
int t1[62][62],t2[62][62],mt1[62][62],mt2[62][62];
__int128 power(__int128 x,__int128 y,__int128 mod){
	__int128 ret=1;
	do{
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
	}while(y>>=1);
	return ret;
}
typedef long double ld;
__int128 mult(ll x, ll y, ll mod) {return (__int128)x*y%mod;}

void Gauss(int n,int mod,int tr[62][62]){
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)a[j][n+1]=((__int128)a[j][n+1]-mult(a[i][n+1],tr[i][j],mod)+mod)%mod;
	for(int i=n;i>=1;i--){
		int val=a[i][n+1];
		for(int j=n;j>i;j--)val=((__int128)val-mult(ans[j],a[i][j],mod)+mod)%mod;
		ans[i]=mult(val,power(a[i][i],mod-2,mod),mod);
		if(ans[i]<0)ans[i]+=mod;
	}
}
void GAO(int n,int mod,int g[62][62]){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i][j]<0)a[i][j]+=mod;
	for(int i=1;i<=n;i++){
		int pos=-1;
		for(int j=i;j<=n;j++)if(a[j][i]!=0){pos=j;break;}
		assert(pos==i);
		for(int j=1;j<=n;j++)swap(a[i][j],a[pos][j]);
		for(int j=i+1;j<=n;j++){
			g[i][j]=mult(a[j][i],power(a[i][i],mod-2,mod),mod);
			for(int t=i;t<=n;t++)a[j][t]=((__int128)a[j][t]-mult(a[i][t],g[i][j],mod)+mod)%mod;
		}
	}
}
int par[62],tar,d[62];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void merge(int x,int y){par[find(x)]=find(y);}
signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>b[i]>>r[i];
		B[b[i]].push_back(i);
		R[r[i]].push_back(i);
	}
	cin>>q;
	memset(mat,0,sizeof mat);
	for(int i=1;i<n;i++){
		mat[i][i]=2;
		for(auto u:B[i])mat[i][u]--;
		for(auto u:R[i])mat[i][u]--;
//		mat[i][n]=(s[i]=='R')-(i==1)+(i==v);
//		for(auto u:B[i])mat[i][n]-=(s[u]=='R');
	}
	memcpy(a,mat,sizeof a);GAO(n-1,md1,t1);memcpy(mt1,a,sizeof mt1);
	memcpy(a,mat,sizeof a);GAO(n-1,md2,t2);memcpy(mt2,a,sizeof mt2);
	while(q--){
		string s;int v;
		cin>>v>>s;s=" "+s;
		memcpy(a,mt1,sizeof mt1);
		for(int i=1;i<n;i++){
			a[i][n]=(s[i]=='R')+(i==1)-(i==v);
			for(auto u:B[i])a[i][n]-=(s[u]=='R');
		}
		Gauss(n-1,md1,t1);memcpy(f1,ans,sizeof f1);
		memcpy(a,mt2,sizeof mt2);
		for(int i=1;i<n;i++){
			a[i][n]=(s[i]=='R')+(i==1)-(i==v);
			for(auto u:B[i])a[i][n]-=(s[u]=='R');
		}
		Gauss(n-1,md2,t2);memcpy(f2,ans,sizeof f2);
		bool can=1;
		for(int i=1;i<n;i++){
			if(f1[i]!=f2[i])can=0;
		}
//		for(int i=1;i<n;i++)cerr<<i<<" "<<f1[i]<<" "<<f2[i]<<endl;
		memset(d,0,sizeof d);
		tar=v;d[v]=1;queue<int>q;
		q.push(v);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(auto u:R[x])if(f1[u])if(!d[u]&&s[u]=='R'){
				d[u]=1;q.push(u);
			}
			for(auto u:B[x])if(f1[u])if(!d[u]&&s[u]=='B'){
				d[u]=1;q.push(u);
			}
		}
		for(int i=1;i<n;i++)if(f1[i])if(!d[i])can=0;
		for(int i=1;i<n;i++)if(f1[i]==0&&s[i]=='R')can=0;
		if(!can){
			cout<<-1<<endl;
			continue;
		}
		int fans=0;
		for(int i=1;i<n;i++)fans+=f1[i]*2-(s[i]=='R');
		cout<<fans<<endl;
	}
	return 0;
}