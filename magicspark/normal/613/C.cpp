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
int n,fuck,sum;
int cnt[26],c[26];
void check_odd(int x){
	for(int i=0;i<n;i++){
		if(cnt[i]%x)return;
		c[i]=cnt[i]/x;
	}
	int odd=0;
	for(int i=0;i<n;i++){
		odd+=c[i]%2;
	}
	if(odd>1)return;
	//good
	cout<<x<<endl;
	for(int _=0;_<x;_++){
		for(int i=0;i<n;i++)if(c[i]%2==0){
			for(int j=0;j<c[i]/2;j++)cout<<(char)('a'+i);
		}
		for(int i=0;i<n;i++)if(c[i]%2){
			for(int j=0;j<c[i];j++)cout<<(char)('a'+i);
		}
		for(int i=n-1;i>=0;i--)if(c[i]%2==0){
			for(int j=0;j<c[i]/2;j++)cout<<(char)('a'+i);
		}
	}
	exit(0);
}
void check_even(int x){
	for(int i=0;i<n;i++){
		if(cnt[i]%x)return;
		c[i]=cnt[i]/x;
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<c[i];j++)s+='a'+i;
	}
	string rs=s;
	reverse(s.begin(),s.end());
	cout<<x<<endl;
	for(int i=0;i<x/2;i++){
		cout<<s<<rs;
	}
	exit(0);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cnt[i];
		fuck+=cnt[i]%2;sum+=cnt[i];
	}
	if(fuck>=2){
		puts("0");
		for(int i=0;i<n;i++)for(int j=0;j<cnt[i];j++)cout<<(char)('a'+i);
		return 0;
	}
	for(int i=sum;i>=1;i--)if(sum%i==0){
		if(i&1)check_odd(i);
		else check_even(i);
	}
	return 0;
}