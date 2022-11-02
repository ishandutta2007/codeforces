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
int n,l,k;
string dat;
string ans[1005];
int pos=0;
char get(){
	return dat[pos++];
}
int lmt=1;
void solve(){
	for(int i=1;i<=l;i++){
		for(int j=lmt;j<=k;j++){
			ans[j].push_back(get());
		}
		while(ans[lmt].back()<ans[k].back())lmt++;
	}
	for(int i=1;i<=k;i++){
		while(ans[i].size()<l)ans[i].push_back(get());
	}
}
int main(){
	cin>>n>>l>>k;
	cin>>dat;
	sort(dat.begin(),dat.end());
	for(int i=n;i>k;i--){
		for(int j=0;j<l;j++){
			char c=dat.back();dat.pop_back();
			ans[i].push_back(c);
		}
	}
	solve();
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}