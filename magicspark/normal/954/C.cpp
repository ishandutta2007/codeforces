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
int n,x,y=-1;
int a[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&abs(a[i]-a[i-1])!=1){
			if(y!=-1&&y!=abs(a[i]-a[i-1])){
				puts("NO");
				return 0;
			}
			y=abs(a[i]-a[i-1]);x=1e9;
		}
	}
	if(y==0){
		puts("NO");
		return 0;
	}
	if(y==-1){
		cout<<"YES"<<endl;
		cout<<(int)1e9<<" "<<(int)1e9<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])==1){
			if(min(a[i],a[i-1])%y==0){
				cerr<<a[i]<<" "<<a[i-1]<<endl;
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	cout<<x<<" "<<y<<endl;
	return 0;
}