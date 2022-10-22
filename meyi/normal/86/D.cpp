#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxa=1e6+10,maxn=2e5+10;
int a[maxn],bel[maxn],cnt,m,n,num[maxa],ql;
struct qry{
	int l,r,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
	}
}q[maxn];
ll ans[maxn],sum;
inline void add(int k){
	sum+=1ll*(num[a[k]]++*2+1)*a[k];
}
inline void del(int k){
	sum-=1ll*(--num[a[k]]*2+1)*a[k];
}
int main(){
	scanf("%d%d",&n,&ql);
	m=sqrt(n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	for(ri i=1;i<=ql;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+ql+1);
	ri l=1,r=0;
	for(ri i=1;i<=ql;++i){
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=sum;
	}
	for(ri i=1;i<=ql;++i)printf("%lld\n",ans[i]);
	return 0;
}