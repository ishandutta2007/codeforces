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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string s[100005];
string ans="";
#define SZ 1000005
int len[SZ],fail[SZ];
void build(string &p){
	int len=p.size(),j=fail[0]=-1;
	for(int i=1;i<=len;i++){
		while(j>=0&&p[j]!=p[i-1])j=fail[j];
		fail[i]=++j;//if(p[fail[i]-1]==p[i-1])fail[i]=fail[fail[i]];
	}
}
int kmp(string &_t,string &_s,int st){
	int n=_t.size(),m=_s.size();
	for(int i=st,k=0;i<n;i++){
		while(k>=0&&_s[k]!=_t[i])k=fail[k];
		len[i]=++k;
	}
	return len[n-1];
}
void add(string &s){
	build(s);
	int x=kmp(ans,s,max((int)ans.size()-(int)s.size(),0));
	for(int i=x;i<s.size();i++)ans.push_back(s[i]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	ans=s[1];
	for(int i=2;i<=n;i++)add(s[i]);
	cout<<ans<<endl;
	return 0;
}