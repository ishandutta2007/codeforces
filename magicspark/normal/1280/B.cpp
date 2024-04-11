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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
//1000pts
int T,n,m;
string s[66];
char buf[66];
string read(){
	scanf("%s",buf);return buf;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)s[i]=" "+read();
		bool can=false,all=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='P')all=false;
				if(s[i][j]=='A')can=true;
			}
		}
		if(!can){
			printf("MORTAL\n");
			continue;
		}
		if(all){
			printf("0\n");
			continue;
		}
		//check 1
		bool bad=false;
		for(int i=1;i<=n;i++)if(s[i][1]=='P')bad=true;
		if(!bad){printf("1\n");continue;}
		bad=false;
		for(int i=1;i<=n;i++)if(s[i][m]=='P')bad=true;
		if(!bad){printf("1\n");continue;}
		bad=false;
		for(int i=1;i<=m;i++)if(s[1][i]=='P')bad=true;
		if(!bad){printf("1\n");continue;}
		bad=false;
		for(int i=1;i<=m;i++)if(s[n][i]=='P')bad=true;
		if(!bad){printf("1\n");continue;}
		if(s[1][1]=='A'||s[n][1]=='A'||s[1][m]=='A'||s[n][m]=='A'){
			printf("2\n");continue;
		}
		bool two=false;
		for(int i=1;i<=n;i++){
			bool tmp=true;
			for(int j=1;j<=m;j++)if(s[i][j]=='P')tmp=false;
			if(tmp)two=true;
		}
		for(int j=1;j<=m;j++){
			bool tmp=true;
			for(int i=1;i<=n;i++){
				if(s[i][j]=='P')tmp=false;
			}
			if(tmp)two=true;
		}
		if(two){
			printf("2\n");
			continue;
		}
		bool three=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==1||i==n||j==1||j==m){
					if(s[i][j]=='A')three=true;
				}
			}
		}
		if(three)printf("3\n");
		else printf("4\n");
	}
	return 0;
}