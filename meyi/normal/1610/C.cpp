#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],b[maxn],m,n,t_case;
inline bool check(int k){
	ri cnt=0;
	for(ri i=1;i<=n;++i)
		if(cnt<=b[i]&&k-cnt-1<=a[i])
			++cnt;
	return cnt>=k;
}
inline int half(){
	ri l=1,r=n,ret=0;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
		printf("%d\n",half());
	}
	return 0;
}