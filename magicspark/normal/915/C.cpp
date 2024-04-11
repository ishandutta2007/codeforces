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
#pragma comment(" -Wl,--stack=1024000000")
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
string a,b;
int cnt[11];
string res;
string Create_Min(){
	string tmp=res;
	for(int i=0;i<=9;i++){
		for(int j=0;j<cnt[i];j++){
			tmp+=(char)('0'+i);
		}
	}
	return tmp;
}
int main(){
	cin>>a>>b;
	if(a.size()<b.size()){
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		cout<<a<<endl;return 0;
	}
	for(int i=0;i<a.size();i++){
		cnt[a[i]-'0']++;
	}
	for(int i=0;i<a.size();i++){
		for(int i=9;i>=0;i--){
			if(cnt[i]){
				res+=(char)('0'+i);cnt[i]--;
				if(Create_Min()<=b)break;
				res.erase(res.end()-1);cnt[i]++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}