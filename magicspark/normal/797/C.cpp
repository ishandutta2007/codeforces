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
string s;
int n,suf[100005][26];
int main(){
	cin>>s;n=s.size();s=" "+s;
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++){
			suf[i][j]=suf[i+1][j];
		}
		suf[i][s[i]-'a']++;
	}
	int pos=0;
	string ans="";
	stack<char>not_used;
	for(int i=1;i<=n;i++){
		while(pos<26&&suf[i][pos]==0)pos++;
		while(not_used.size()&&not_used.top()<='a'+pos){
			ans+=not_used.top();not_used.pop();
		}
		if(pos==26)break;
		if(s[i]=='a'+pos){
			ans+=s[i];
		}else{
			not_used.push(s[i]);
		}
	}
	while(not_used.size()){
		ans+=not_used.top();not_used.pop();
	}
	cout<<ans<<endl;
	return 0;
}