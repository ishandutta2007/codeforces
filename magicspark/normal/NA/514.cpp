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
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
inline int Rand(){return rand()*32768+rand();}
const int v=1e7+100;
int t,f[v*2];
const int mod=1e7;
struct mat{
	int a,b,c,d;
	mat(){}
}a,b,c;
int func(int x,int y,int z,int w){
	__int128 vv=(__int128)x*z+(__int128)y*w;
	vv=vv%(int)1e13;return (int)vv;
}
mat mul(mat x,mat y){
	mat ret;
	ret.a=func(x.a,x.c,y.a,y.b);
	ret.b=func(x.b,x.d,y.a,y.b);
	ret.c=func(x.a,x.c,y.c,y.d);
	ret.d=func(x.b,x.d,y.c,y.d);
	return ret;
}
mat power(mat a,int y){
	mat m=a;
	a.a=1;a.b=0;a.c=0;a.d=1;
	do{
		if(y&1)a=mul(a,m);
		m=mul(m,m);
	}while(y>>=1);
	return a;
}
signed main(){
	f[0]=0;f[1]=1;
	for(int i=2;i<=1.6e7;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	const int len=1.5e7;
	int t;cin>>t;
	vector<int>cand;
	for(int i=0;i<len;i++){
		if(f[i]==t%mod){
			cand.push_back(i);
		}
	}
	if(cand.empty()){
		puts("-1");
		return 0;
	}
	int ans=1e18;
	for(auto rem:cand){
		a.a=1;a.b=0;a.c=0;a.d=1;
		c.a=1;c.b=0;c.c=0;c.d=1;
		b.a=1;b.b=1;b.c=1;b.d=0;
		a=power(b,len);
		c=power(b,rem);
		for(int i=0;i<=1e6;i++){
			if(i*len+rem>ans)break;
			if(c.b==t){
				ans=min(ans,i*len+rem);
				break;
			}
			c=mul(c,a);
		}
	}
	if(ans==1e18)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}