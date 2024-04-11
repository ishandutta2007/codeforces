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
int T,x,hv[1000005];
string s;
bool can(int pos){
	bool ret=1;
	if(pos>x)ret&=s[pos-x]=='1';
	if(pos+x<s.size())ret&=s[pos+x]=='1';
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		memset(hv,0,sizeof hv);
		cin>>s>>x;s=" "+s;
		string ans=" ";
		for(int i=1;i<s.size();i++){
			if(can(i))ans.push_back('1');
			else ans.push_back('0');
		}
		bool go=1;
		for(int i=1;i<s.size();i++){
			if(s[i]=='1'){
				if(i-x>0&&ans[i-x]=='1')continue;
				if(i+x<s.size()&&ans[i+x]=='1')continue;
				go=0;
			}
		}
		ans.erase(ans.begin());
		if(go)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}