/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n;
char op[200005];
int val[200005],ans[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>op[i];
		if(op[i]=='-')cin>>val[i];
	}
	set<int>st;
	for(int i=n*2;i>=1;i--){
		if(op[i]=='-'){
			st.insert(val[i]);
		}else{
			if(!st.size()){
				puts("NO");
				return 0;
			}
			ans[i]=*st.begin();
			st.erase(st.begin());
		}
	}
	st.clear();
	for(int i=1;i<=n*2;i++){
		if(op[i]=='+'){
			st.insert(ans[i]);
		}else{
			if(*st.begin()!=val[i]){
				puts("NO");
				return 0;
			}
			st.erase(st.begin());
		}
	} 
	puts("YES");
	for(int i=1;i<=n*2;i++)if(op[i]=='+')cout<<ans[i]<<" ";
	return 0;
}