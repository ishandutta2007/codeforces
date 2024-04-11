/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
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
int dp[2005][2005];
int pres[2005][26],pret[2005][26];
int nxt[2005][26];
int T,n;
string s,t;
int get_s(int l,int r,int ind){
	return pres[r][ind]-pres[l-1][ind];
}
int get_t(int l,int r,int ind){
	return pret[r][ind]-pret[l-1][ind];
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s>>t;
		s=" "+s;t=" "+t;
		for(int i=0;i<26;i++)nxt[0][i]=-1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++){
				pres[i][j]=pres[i-1][j];
				pret[i][j]=pret[i-1][j];
				nxt[i][j]=nxt[i-1][j];
			}
			pres[i][s[i]-'a']++;
			pret[i][t[i]-'a']++;
			nxt[i][s[i]-'a']=i;
		}
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=n+1;j++){
				dp[i][j]=inf;
			}
		}
		dp[n+1][n+1]=0;
		//first->s,second->t
		for(int i=n+1;i>=1;i--){
			for(int j=n+1;j>=2;j--){
				int pos=t[j-1]-'a';
				if(get_s(i,n,pos)>get_t(j,n,pos)){
					dp[i][j-1]=min(dp[i][j-1],dp[i][j]);
				}
				int prv=nxt[i-1][pos];if(prv<0)continue;
				dp[prv][j-1]=min(dp[prv][j-1],dp[i][j]+(i-prv-1));
			}
		}
		cout<<(dp[1][1]==inf?-1:dp[1][1])<<endl;
	}
	return 0;
}