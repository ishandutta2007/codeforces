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
int t1,t2,n,m,l[100005],r[100005];
int col[100005],id[100005];
vector<int>g[100005];
void dfs(int x,int c){
	col[x]=c;
	for(auto to:g[x]){
		if(!col[to]){
			dfs(to,3-c);
		}else{
			if(col[to]+col[x]!=3){
				puts("IMPOSSIBLE");
				exit(0);
			}
		}
	}
}
int main(){
	cin>>t1>>t2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	int L=*max_element(l+1,l+n+1),R=*min_element(r+1,r+n+1);
	if(L+R<t1)L+=(t1-L-R);
	if(L+R>t2)R-=(L+R-t2);
	if(L<0||R<0){
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool can1=1,can2=1;
		if(r[i]<R||l[i]>R){
			can1=0;
		}
		if(r[i]<L||l[i]>L){
			can2=0;
		}
		if(!can1&&!can2){
			puts("IMPOSSIBLE");
			exit(0);
		}
		if(can1&&can2){
			continue;
		}
		if(can1)col[i]=1;
		else col[i]=2;
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(col[i])dfs(i,col[i]);
	}
	for(int i=1;i<=n;i++){
		if(!col[i])col[i]=1,dfs(i,col[i]);
	}
	puts("POSSIBLE");
	cout<<R<<" "<<L<<endl;
	for(int i=1;i<=n;i++)cout<<col[i];
	return 0;
}