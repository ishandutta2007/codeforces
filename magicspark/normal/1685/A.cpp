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
int T,n,a[100005],b[100005];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n&1){
			cout<<"NO"<<endl;
			continue;
		}
		sort(a+1,a+n+1);
		int pos=1;
		for(int i=1;i<=n;i+=2)b[i]=a[pos++];
		for(int i=2;i<=n;i+=2)b[i]=a[pos++];
		bool can=1;
		for(int i=1;i<=n;i++){
			int nxt=i%n+1;
			if(b[i]==b[nxt]){
				can=0;
				break;
			}
		}
		if(!can){
			cout<<"NO"<<endl;
			for(int i=1;i<=n;i++)cerr<<b[i]<<" ";cerr<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
	}
	return 0;
}