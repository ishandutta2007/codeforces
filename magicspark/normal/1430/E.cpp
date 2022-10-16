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
string s;
string rs;
int arr[200005];
struct bit{
	ll f[200005];
	void add(int x,int v){
		x++;
		while(x<=2e5+2){
			f[x]+=v;x+=x&-x;
		}
	}
	ll sum(int x){
		x++;
		if(x<=0)return 0;
		ll ret=0;
		while(x){
			ret+=f[x];
			x-=x&-x;
		}
		return ret;
	}
}T;
int main(){
	cin>>n>>s;rs=s;
	reverse(rs.begin(),rs.end());
	for(int i=0;i<26;i++){
		vector<int>pos;
		for(int j=0;j<n;j++){
			if(s[j]=='a'+i){
				pos.push_back(j);
			}
		}
		int p=0;
		for(int j=0;j<n;j++){
			if(rs[j]=='a'+i){
				arr[j]=pos[p++]+1;
			}
		}
	}
	ll res=0;
	for(int i=0;i<n;i++){
		cerr<<arr[i]<<" ";
		res+=T.sum(n+1)-T.sum(arr[i]);
		T.add(arr[i],1);
	}cerr<<endl;
	cout<<res<<endl;
	return 0;
}