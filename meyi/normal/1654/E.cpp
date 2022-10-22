#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int B=318,maxn=1e5+10;
int a[maxn],ans,m,n,t_case;
template<class T>
inline int calc(vector<T> &v){
	int cnt=0,ret=0;
	T lst=numeric_limits<T>::max();
	sort(v.begin(),v.end());
	for(ll i:v){
		if(i!=lst)ckmax(ret,cnt),cnt=1,lst=i;
		else ++cnt;
	}
	return max(cnt,ret);
}
int main(){
	scanf("%d",&n);
	if(n<3)return putchar(48),0;
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	ans=n-2;
	for(ri i=-B;i<=B;++i){
		vector<ll>v;
		v.reserve(n);
		for(ri j=1;j<=n;++j)v.push_back(a[j]+1ll*j*i);
		ckmin(ans,n-calc(v));
	}
	for(ri i=1;i<=n;++i){
		vector<int>v;
		for(ri j=i+1;j<=n&&j<=i+B;++j)
			if((a[j]-a[i])%(j-i)==0)
				v.push_back((a[j]-a[i])/(j-i));
		ckmin(ans,n-1-calc(v));
	}
	printf("%d",ans);
	return 0;
}