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
int T,n,k;
int ask(vector<int>a,vector<int>b){
	set<int>A,B,C;
	for(auto vv:a)A.insert(vv);
	for(auto vv:b)B.insert(vv);
	for(auto t:A)if(B.count(t))C.insert(t);
	for(auto t:C)A.erase(t),B.erase(t);
	cout<<"? "<<A.size()<<" "<<B.size()<<endl;
	for(auto aa:A)cout<<aa<<" ";cout<<endl;
	for(auto bb:B)cout<<bb<<" ";cout<<endl;
	fflush(stdout);
	string s;cin>>s;
	if(s=="WASTED")assert(0);
	return s=="FIRST"?2:s=="EQUAL"?1:0;
}
vector<int>get_vector(int l,int r){
	vector<int>ret;
	for(int i=l;i<=r;i++)ret.push_back(i);
	return ret;
}
void search(int l,int r){
	l--;
	while(r-l>1){
		int mid=(l+r)/2;
		if(ask(get_vector(1,mid-l),get_vector(l+1,mid))==1)l=mid;
		else r=mid;
	}
	cout<<"! "<<r<<endl;
} 
void solve(){
	set<int>random;
	while(random.size()<=25&&random.size()<n-1){
		int x=rand()%(n-1)+2;
		random.insert(x);
	}
	set<int>verdict;
	for(auto x:random){
		verdict.insert(ask({1},{x}));
	}
	if(verdict.count(0)){
		cout<<"! 1"<<endl;
		return;
	}
	int cur=1;
	while(cur*2<=n){
		int cmp=ask(get_vector(1,cur),get_vector(cur+1,cur*2));
		if(cmp==1){
			cur*=2;
		}else{
			search(cur+1,cur*2);
			return;
		}
	}
	search(cur+1,n);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		solve();
		fflush(stdout);
	}
	return 0;
}