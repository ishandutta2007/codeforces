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
int T,n,l,a[100005];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>l;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[0]=0;a[n+1]=l;
		int l=0,r=n+1,sl=1,sr=1;
		double cl=0,cr=0;
		while(r-l>1){
			double al=1.0*(a[l+1]-a[l])/sl+cl;
			double ar=1.0*(a[r]-a[r-1])/sr+cr;
			if(al<ar){
				l++;sl++;
				cl=al;
			}else{
				r--;sr++;
				cr=ar;
			}
		}
		cerr<<cl<<" "<<cr<<endl;
//		assert(cl==cr);
		double sub=0;
		if(cl>cr){
			sub=(cl-cr)*sr;
		}else{
			sub=(cr-cl)*sl; 
		}
		printf("%.10lf\n",max(cl,cr)+1.0*(1.0*a[r]-1.0*a[l]-sub)/(sr+sl));
	}
	return 0;
}