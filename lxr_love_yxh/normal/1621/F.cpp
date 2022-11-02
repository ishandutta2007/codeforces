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
int T,n,a,b,c,one,ans,lmt;
bool check(multiset<int>&s){
	auto itr=s.lower_bound(2);
	if(itr==s.end())return false;
	if(*itr<inf)return true;
	auto it2=s.rbegin();
	if(*it2%inf>1)return true;
	return false;
}
void solve(int op,multiset<int>s){
	int cur=0,tms=0;
	for(int i=op;;i^=1){
		if(i==0){
			if(!s.size())return;
			if(one==0){
				auto itr=s.begin();
				ans=max(ans,cur+(check(s)?a:-c));
				if(*itr>1)return;
				cur-=c;s.erase(s.begin());
				one++;
			}else{
				auto itr=s.lower_bound(2);
				if(itr==s.end())itr--;
				while(itr!=s.end()&&*itr==inf+1)itr++;
				if(itr==s.end())itr--;
				cur+=(*itr%inf==1?-c:a);
				auto ins=*itr-1;
				s.erase(itr);
				if(ins%inf)s.insert(ins);
			}
		}else{
			if(!one||tms==lmt-1)return;
			one--;cur+=b;tms++;
		}
//		cerr<<i<<" "<<cur<<endl;
		ans=max(ans,cur);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>T;string s;
	while(T--){
		cin>>n>>a>>b>>c>>s;
		one=0;ans=0;lmt=0;
		for(char c:s)if(c=='1')lmt++;
		for(int i=1;i<n;i++)if(s[i]==s[i-1]){
			if(s[i]=='1')one++;
		}
		multiset<int>ss;
		for(int i=0;i<n;i++)if(s[i]=='0')if(i==0||s[i-1]=='1'){
			int j=i;while(j<n&&s[j]=='0')j++;
			ss.insert(j-i+(i==0||j==n?inf:0));
		}
		solve(0,ss);
		one=0;
		for(int i=1;i<n;i++)if(s[i]==s[i-1]){
			if(s[i]=='1')one++;
		}
		solve(1,ss);
		cout<<ans<<endl;
	}
	return 0;
}