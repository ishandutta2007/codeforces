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
int n,cur,base;
int a[400005],b[400005];
bool cmp(int x,int y){
	return (x&base)<(y&base);
}
int query(int bs,int pos,int l,int r,int v=0){
	if(r<l)return 0;
	l=(pos<<cur-1)+l;r=(pos<<cur-1)+r;
//	if(base==1)cerr<<"ask: "<<pos<<" "<<l<<" "<<r<<" "<<v<<endl;
	return upper_bound(b+1,b+n+1,r)-lower_bound(b+1,b+n+1,l);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=25;i>=0;i--){
		cur=i+1;base=(1<<cur)-1; 
		sort(a+1,a+n+1,cmp);
		for(int j=1;j<=n;j++)b[j]=a[j]&base;
		ll cnt=0;
		for(int j=1;j<=n;j++){
			int suf=a[j]&((1<<i)-1);
			cnt+=query(base,1-(a[j]>>i)%2,0,(1<<i)-1-suf,a[j]*1e5+1);
			cnt+=query(base,(a[j]>>i)%2,(1<<i)-suf,(1<<i)-1,a[j]*1e5+2);
		}
		for(int j=1;j<=n;j++)if((a[j]+a[j])&(1<<i))cnt--;
		cnt/=2;if(cnt)cerr<<i<<" "<<cnt<<endl;
		if(cnt&1)ans|=(1<<i);
	}
	cout<<ans<<endl;
	return 0;
}