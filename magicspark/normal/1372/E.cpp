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
int pre[105][105],mem[105][105];
int solve(int l,int r){
	if(l>r)return 0;
	if(~mem[l][r])return mem[l][r];
	int ret=0;
	for(int i=l;i<=r;i++){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(pre[j][i]-pre[j][l-1]&&pre[j][r+1]-pre[j][i])tot++;
		}
		ret=max(ret,tot*tot+solve(l,i-1)+solve(i+1,r));
	}
	return mem[l][r]=ret;
}
int main(){
	memset(mem,-1,sizeof mem);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		while(t--){
			int l,r;cin>>l>>r;
			pre[i][l]++;
		}
		for(int j=1;j<=m;j++)pre[i][j]+=pre[i][j-1];
	}
	cout<<solve(1,m)<<endl;
	return 0;
}