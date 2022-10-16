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
int T,n;
map<int,int>cnt;
pair<int,int>mx[400005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cnt.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;cin>>x;cnt[x]++;
		}
		int most=n/2;
		int useless=n-most;
		while(useless>0){
			useless-=cnt.begin()->second;
			cnt.erase(cnt.begin());
		}
		if(!cnt.size()){
			cout<<("0 0 0")<<endl;
			continue;
		}
		vector<int>vals;
		for(map<int,int>::reverse_iterator itr=cnt.rbegin();itr!=cnt.rend();itr++){
			vals.push_back(itr->second);
		}
		int g=0,s=0,b=0,i=1;
		g=vals[0];
		for(;s<=g&&i<vals.size();i++){
			s+=vals[i];
		}
		for(;b<=g&&i<vals.size();i++){
			b+=vals[i];
		}
		if(s<=g||b<=g){
			cout<<("0 0 0")<<endl;
		}else{
			for(;i<vals.size();i++)b+=vals[i];
			cout<<g<<" "<<s<<" "<<b<<endl;
		}
	}
	return 0;
}