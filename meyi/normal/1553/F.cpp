#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10,mx=3e5;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c1;
BIT<ll>c2;
int a[maxn],n;
ll ans,pre;
signed main(){
	scanf("%d",&n);
	c1.mx_idx=c2.mx_idx=mx;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		ans+=pre;
		pre+=a[i];
		for(ri j=a[i];j<=mx;j+=a[i])ans-=1ll*c1.query(j,min(j+a[i]-1,mx))*j;
		c1.add(a[i],1);
		ans+=1ll*(i-1)*a[i]-c2.query(a[i]);
		for(ri j=a[i];j<=mx;j+=a[i])c2.add(j,a[i]);
		printf("%lld ",ans);
	}
	return 0;
}