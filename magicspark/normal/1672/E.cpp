/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
int main(){
	cin>>n;
	int l=0,r=1e7;
	while(r-l>1){
		int mid=(l+r)/2;
		cout<<"? "<<mid<<endl;
		fflush(stdout);
		int x;cin>>x;
		if(x==1)r=mid;
		else l=mid;
	}
	int tot=r-n+1,ans=r;
	for(int i=1;i<=n;i++){
		int sum=tot+i-1;sum/=i;
		while(sum*i<r)sum++;
		while(sum*i>=r)sum--;
		if(!sum)continue;
		cout<<"? "<<sum<<endl;
		fflush(stdout);
		int x;cin>>x;
		if(x<=i&&x)ans=min(ans,sum*i);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}