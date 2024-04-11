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
int T,n,k;
int a[100005],b[100005];
int pre[100005],suf[100005],p[100005],s[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i],b[i]=(a[i]>=k?1:-1);
		if(n==1){
			if(a[1]==k)puts("yes");
			else puts("no");
			continue;
		}
		for(int i=0;i<=n+3;i++)pre[i]=suf[i]=p[i]=s[i]=0;
		pre[0]=0;suf[n+1]=0;
		p[0]=0;s[n+1]=0;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+b[i];
			p[i]=min(p[i-1],pre[i]);
		}
		for(int i=n;i>=1;i--){
			suf[i]=suf[i+1]+b[i];
			s[i]=min(s[i+1],suf[i]);
		}
		bool ans=0;
		for(int i=1;i<=n;i++){
			int sum=pre[n];
			sum-=min(p[i-1]+(i==n?inf:s[i+2]),
			(i==1?inf:p[i-2])+s[i+1]);
			if(sum>0)ans=1;
		}
		bool res=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)res=1;
		}
		puts(ans&&res?"yes":"no");
	}
	return 0;
}