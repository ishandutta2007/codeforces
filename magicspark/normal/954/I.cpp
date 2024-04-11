/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
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
struct Bitset{
	int n;unsigned dat[200032/32];
	void init(int x){
		n=(x+31)/32;
	}
	bool operator>>=(int x){
		const int mask=(1<<x)-1;
		for(int i=0;i<n;i++){
			dat[i]>>=x;dat[i]|=(dat[i+1]&mask)<<(32-x);
		}
	}
	void set(int x){
		dat[x/32]|=(1u<<(x&31));
	}
	bool any(){
		for(int i=0;i<n;i++)if(dat[i])return true;
		return false;
	}
	Bitset operator&(Bitset &b){
		Bitset ret;ret.init(n*32);
		for(int i=0;i<n;i++){
			ret.dat[i]=dat[i]&b.dat[i];
		}
		return move(ret);
	}
};
Bitset ss[6],tt[6];
string s,t;
int par[6];
inline int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
	par[find(x)]=find(y);
}
int main(){
	cin>>s>>t;
	for(int i=0;i<6;i++)ss[i].init(t.size()),tt[i].init(t.size());
	for(int i=0;i<t.size();i++)ss[s[i]-'a'].set(i);
	for(int i=0;i<t.size();i++)tt[t[i]-'a'].set(i);
	for(int i=t.size();i<=s.size();i++){
		for(int j=0;j<6;j++)par[j]=j;
		for(int a=0;a<6;a++){
			for(int b=0;b<6;b++){
				if(find(a)==find(b))continue;
				if((ss[a]&tt[b]).any())merge(a,b);
			}
		}
		int ans=0;
		for(int j=0;j<6;j++)if(find(j)!=j){
			ans++;
		}
		printf("%d ",ans);
		for(int j=0;j<6;j++)ss[j]>>=1;
		if(i!=s.size())ss[s[i]-'a'].set(t.size()-1);
	}
	return 0;
}