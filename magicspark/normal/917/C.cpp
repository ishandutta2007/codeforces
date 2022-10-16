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
int x,k,n,q;
int c[55];
pair<int,int>p[55];
map<int,int>mp;
int id[1<<8],tot;
int to[123];
int mat[75][75],pos;
int a[75][75],b[75][75],d[75][75];
int dp[75],tdp[75];
void mult(int a[75][75],int b[75][75],int c[75][75]){
	for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)a[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<tot;i++)for(int j=0;j<tot;j++){
		for(int k=0;k<tot;k++){
			a[i][j]=min(a[i][j],b[i][k]+c[k][j]);
		}
	}
}
void trans(){
	memset(tdp,inf,sizeof tdp);
	for(int i=0;i<tot;i++){
		int mask=to[i];
		if(mask&1){
			for(int j=1;j<=k;j++){
				if(mask&(1<<j))continue;
				int cost=c[j]+(mp.count(pos+j)?mp[pos+j]:0);
				tdp[id[(mask|(1<<j))>>1]]=min(tdp[id[(mask|(1<<j))>>1]],dp[i]+cost);
			}
		}else tdp[id[mask>>1]]=min(tdp[id[mask>>1]],dp[id[mask]]);
	}
	memcpy(dp,tdp,sizeof dp);
}
signed main(){
	cin>>x>>k>>n>>q;
	pos=x;
	for(int i=1;i<=k;i++)cin>>c[i];
	for(int i=1;i<=q;i++)cin>>p[i].first>>p[i].second,mp[p[i].first]+=p[i].second;
	sort(p+1,p+q+1);
	memset(id,-1,sizeof id);
	for(int i=0;i<(1<<k);i++)if(__builtin_popcount(i)==x){
		to[tot]=i;id[i]=tot++;
	}
	memset(mat,inf,sizeof mat);
	for(int i=0;i<tot;i++){
		int mask=to[i];
		if(mask&1){
			int new_mask=mask-1;
			for(int j=1;j<=k;j++){
				if(mask&(1<<j))continue;
				new_mask=(mask-1)|(1<<j);
				mat[id[mask]][id[new_mask>>1]]=min(mat[id[mask]][id[new_mask>>1]],c[j]);
			}
		}else mat[id[mask]][id[mask>>1]]=0;
	}
	pos=1;
	//target pos=n-k+1;
	memset(dp,inf,sizeof dp);
	int mask=0;
	for(int i=0;i<x;i++)mask|=(1<<i);
	dp[id[mask]]=0; 
	for(int i=1;i<=q;i++){
		if(pos<p[i].first-k-1){
			int len=(p[i].first-k-1)-pos;
			memcpy(a,mat,sizeof a);
			memcpy(b,mat,sizeof b);
			len--;
			do{
				if(len&1){
					mult(d,a,b);
					memcpy(a,d,sizeof a);
				}
				mult(d,b,b);
				memcpy(b,d,sizeof d);
			}while(len>>=1);
			memset(tdp,inf,sizeof tdp);
			for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)tdp[j]=min(tdp[j],dp[i]+a[i][j]);
			memcpy(dp,tdp,sizeof dp);
			pos=p[i].first-k-1;
		}
//		for(int j=0;j<tot;j++)cerr<<dp[j]<<" ";cerr<<endl;
		while(pos<=p[i].first&&pos<n-x+1)trans(),pos++;
//		for(int j=0;j<tot;j++)cerr<<dp[j]<<" ";cerr<<endl;
//		cerr<<"---------------"<<endl;
	}
//	cerr<<pos<<" "<<n-x+1<<endl;
//	for(int j=0;j<tot;j++)cerr<<dp[j]<<" ";cerr<<endl;
	if(pos<n-x+1){
		int len=(n-x+1)-pos;
		cerr<<len<<endl;
		memcpy(a,mat,sizeof a);
		memcpy(b,mat,sizeof b);
		len--;
		do{
			if(len&1){
				mult(d,a,b);
				memcpy(a,d,sizeof a);
			}
			mult(d,b,b);
			memcpy(b,d,sizeof d);
		}while(len>>=1);
		memset(tdp,inf,sizeof tdp);
		for(int i=0;i<tot;i++){
			for(int j=0;j<tot;j++){
				cerr<<a[i][j]<<" ";
			}
			cerr<<endl;
		}
		for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)tdp[j]=min(tdp[j],dp[i]+a[i][j]);
		memcpy(dp,tdp,sizeof dp);
		pos=n-x+1;
	}
	assert(pos==n-x+1);
	mask=0;
	for(int i=0;i<x;i++)mask|=(1<<i);
	cout<<dp[id[mask]]<<endl;
	return 0;
}