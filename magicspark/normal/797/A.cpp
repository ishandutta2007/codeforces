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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
multiset<int>S;
int n,k;
int main(){
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				n/=i;S.insert(i);
			}
		}
	}
	if(S.size()<k){
		puts("-1");
	}else{
		while(S.size()>k){
			int x1=*S.begin();S.erase(S.begin());
			int x2=*S.begin();S.erase(S.begin());
			S.insert(x1*x2);
		}
		for(multiset<int>::iterator itr=S.begin();itr!=S.end();itr++){
			cout<<*itr<<" ";
		}
	}
	return 0;
}