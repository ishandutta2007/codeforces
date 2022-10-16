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
#define int long long
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
int n,a[100005],b[100005],ans[100005],ord[66],sz,pos[66];
int base[66],path[66],val[66];
void insert(int x){
	int mask=0,ori=x;
	for(int i=60;i>=0;i--){
		if(x&(1ll<<i)){
			if(base[i])x^=base[i],mask^=path[i];
			else{
				base[i]=x;path[i]=mask^(1ll<<i);val[i]=ori;break;
			}
		}
	}
}
multiset<int>solve(){
	int mask=0,cur=0;
	for(int i=60;i>=0;i--){
		if(cur&(1ll<<i))continue;
		if(base[i]){
			cur^=base[i];
			mask^=path[i];
		}
	}
	multiset<int>ret;int chk=0;
	for(int i=0;i<=60;i++){
		if(mask&(1ll<<i))chk^=val[i],ret.insert(val[i]);
	}
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>f0,f1;
	for(int i=60;i>=0;i--){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<i))tot++;
		}
		if(tot%2)f1.push_back(i);
		else f0.push_back(i);
	}
	for(auto v:f0)ord[++sz]=v;
	for(auto v:f1)ord[++sz]=v;
	for(int i=1;i<=sz;i++)pos[ord[i]]=i;
	int high=sz-1;
	for(int i=1;i<=sz;i++){
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<ord[i])){
				b[j]|=(1ll<<high);
			}
		}
		high--;
	}
	assert(high==-1);
	for(int i=1;i<=n;i++){
		insert(b[i]);
	}
	multiset<int>s=solve();
	for(int i=1;i<=n;i++){
		if(s.count(b[i])){
			ans[i]=2;
			s.erase(s.find(b[i]));
		}else ans[i]=1;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}