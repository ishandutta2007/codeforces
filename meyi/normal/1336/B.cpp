#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],c[maxn],m,n,t_case,x,y,z;
inline int pre(int *arr,int len,int val){
	ri pos=lower_bound(arr+1,arr+len+1,val)-arr;
	if(pos>len||arr[pos]>val)--pos;
	return pos>0?arr[pos]:-1;
}
inline int nxt(int *arr,int len,int val){
	ri pos=upper_bound(arr+1,arr+len+1,val)-arr;
	return pos<=len?arr[pos]:-1;
}
inline ll sqr(ll k){return k*k;}
inline ll calc(ll x,ll y,ll z){
	if(min({x,y,z})<1)return LLONG_MAX;
	return sqr(x-y)+sqr(y-z)+sqr(z-x);
}
ll ans;
inline ll calc(ll x,ll y,int *arr,int len){
	if(min(x,y)<1||sqr(x-y)>=ans)return LLONG_MAX;
	ll mid=x+y>>1;
	return min(calc(x,y,pre(arr,len,mid)),calc(x,y,nxt(arr,len,mid)));
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&x,&y,&z);
		for(ri i=1;i<=x;++i)scanf("%d",a+i);
		sort(a+1,a+x+1);
		for(ri i=1;i<=y;++i)scanf("%d",b+i);
		sort(b+1,b+y+1);
		for(ri i=1;i<=z;++i)scanf("%d",c+i);
		sort(c+1,c+z+1);
		ans=LLONG_MAX;
		for(ri i=1;i<=x;++i){
			ckmin(ans,calc(a[i],pre(b,y,a[i]),c,z));
			ckmin(ans,calc(a[i],nxt(b,y,a[i]),c,z));
			ckmin(ans,calc(a[i],pre(c,z,a[i]),b,y));
			ckmin(ans,calc(a[i],nxt(c,z,a[i]),b,y));
		}
		printf("%lld\n",ans);
	}
	return 0;
}