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
int n,m;
string s[1005];
int par[1005*1005];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void merge(int x,int y){par[find(x)]=find(y);}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<1005*1005;i++)par[i]=i; 
	for(int i=1;i<=n;i++)cin>>s[i],s[i]=" "+s[i];
	bool r=0,c=0;
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=1;j<=m;j++){
			if(cur==0&&s[i][j]=='#')cur=1;
			if(cur==1&&s[i][j]=='.')cur=2;
			if(cur==2&&s[i][j]=='#')cur=3;
		}
		if(cur==3){
			puts("-1");
			return 0;
		}
	}
	for(int j=1;j<=m;j++){
		int cur=0;
		for(int i=1;i<=n;i++){
			if(cur==0&&s[i][j]=='#')cur=1;
			if(cur==1&&s[i][j]=='.')cur=2;
			if(cur==2&&s[i][j]=='#')cur=3;
		}
		if(cur==3){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		bool can=1;
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#')can=0;
		}
		r|=can;
	}
	for(int i=1;i<=m;i++){
		bool can=1;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='#')can=0;
		}
		c|=can;
	}
	if(r^c){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'){
				for(int k=0;k<4;k++){
					int ni=i+dx[k],nj=j+dy[k];
					if(ni<=0||nj<=0||ni>n||nj>m||s[ni][nj]=='.')continue;
					merge(i*m+j,ni*m+nj);
				}
			}
		}
	}
	set<int>st;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='#')st.insert(find(i*m+j));
	cout<<st.size()<<endl;
	return 0;
}