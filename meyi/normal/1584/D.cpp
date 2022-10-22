#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
inline ll query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	ll ret;
	scanf("%lld",&ret);
	return ret;
}
int a[maxn],m,n,t_case;
inline ll calc(ll k){
	return k*(k-1)>>1;
}
inline ll rev(ll k){
	ri l=1,r=n,ret;
	while(l<=r){
		ll mid=l+r>>1;
		if(calc(mid)<=k)ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri i,l=1,r=n;
		while(l<=r){
			ri mid=l+r>>1;
			if(!query(1,mid))i=mid,l=mid+1;
			else r=mid-1;
		}
		ll all=query(1,n);
		ll tmp1=query(i+1,n);
		ri len1=all-tmp1+1;
		ll tmp2=all-calc(len1);
		ri len2=rev(tmp2);
		printf("! %d %d %d\n",i,i+len1,i+len1+len2-1);
		fflush(stdout);
	}
	return 0;
}