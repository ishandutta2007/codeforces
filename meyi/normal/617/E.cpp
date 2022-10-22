#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,maxv=1<<21;
int a[maxn],bel[maxn],cnt,m,n,t,tmp[maxv],v;
struct query{
	int l,r,id;
	inline bool operator<(const query &k)const{
		return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
	}
}q[maxn];
ll ans[maxn],sum;
inline void add(int k){
	sum+=tmp[k^v];
	++tmp[k];
}
inline void del(int k){
	--tmp[k];
	sum-=tmp[k^v];
}
int main(){
	scanf("%d%d%d",&n,&t,&v);
	m=sqrt(n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		a[i]^=a[i-1];
		if(i%m==0)++cnt;
		bel[i]=cnt;
	}
	for(ri i=1;i<=t;++i)scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].id=i;
	sort(q+1,q+t+1);
	ri pl=0,pr=0;
	tmp[0]=1;
	for(ri i=1;i<=t;++i){
		while(pl<q[i].l)del(a[pl++]);
		while(pl>q[i].l)add(a[--pl]);
		while(pr<q[i].r)add(a[++pr]);
		while(pr>q[i].r)del(a[pr--]);
		ans[q[i].id]=sum;
	}
	for(ri i=1;i<=t;++i)printf("%lld\n",ans[i]);
	return 0;
}