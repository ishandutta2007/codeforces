/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
string s;
int c=0,n;
map<int,int>id;
int arr[105];
int mul(int x,int y,int mod){
	memset(arr,0,sizeof arr);
	for(int i=0;i<35;i++)if(x&(1ll<<i))for(int j=0;j<35;j++)if(y&(1ll<<j))arr[i+j]^=1;
	for(int i=70;i>=n;i--)if(arr[i]){
		for(int j=i;j>i-n;j--)if(mod&(1ll<<j-(i-n)-1))arr[j]^=1;
	}
	int ret=0;
	for(int i=n-1;i>=0;i--)ret=(ret<<1)+arr[i];
	return ret;
}
signed main(){
	cin>>s;
	if(s.find('1')==string::npos){
		puts("-1");return 0;
	}
	while(s[0]=='0'){
		s.erase(s.begin());c++;
	}
	while(s.back()=='0')s.pop_back();
	if(s.size()==1){
		cout<<c+1<<" "<<c+2<<endl;
		return 0;
	}
	int tot=0;
	for(char c:s)if(c=='1')tot++;
	if(tot==2){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1')cout<<1+i+c<<" ";
		}
		cout<<endl;return 0;
	}
	n=s.size();id[0]=1;int cur=1;
	int val=0;
	for(char c:s)val=(val<<1)+(c=='1');
	for(int i=1;i<(1<<18);i++){
		cur=cur<<1;
		if(cur&(1ll<<n))cur^=(val<<1);
		id[cur]=i;
	}
	cur=cur<<1;
	if(cur&(1ll<<n))cur^=(val<<1);
	int tmp=1;
	for(int i=1;i<(1<<18);i++){
		tmp=mul(tmp,cur,val);
		if(id.count(tmp)){
			cout<<1+c<<" "<<1+c+(i<<18)-id[tmp]<<endl;
			return 0;
		}
	}
	assert(0);
	return 0;
}