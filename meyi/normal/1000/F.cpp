#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10,maxp=1e3+10;
int a[maxn],ans[maxn],bel[maxn],cnt,kbel[maxn],kcnt,kl[maxp],km=708,kr[maxp],ksum[maxp],m,n,num[maxn],ql;
struct qry{
	int l,r,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?l<k.l:(bel[l]&1)?r<k.r:r>k.r;
	}
}q[maxn];
inline void add(int k){
	if(!num[k])++ksum[kbel[k]];
	if(num[k]==1)--ksum[kbel[k]];
	++num[k];
}
inline void del(int k){
	if(num[k]==1)--ksum[kbel[k]];
	if(num[k]==2)++ksum[kbel[k]];
	--num[k];
}
inline int query(){
	for(ri i=1;i<=kcnt;++i)
		if(ksum[i])
			for(ri j=kl[i];j<=kr[i];++j)
				if(num[j]==1)
					return j;
	return 0;
}
int main(){
	for(ri i=1;i<500001;++i){
		if(i%km==1)kr[kcnt]=i-1,kl[++kcnt]=i;
		kbel[i]=kcnt;
	}
	kr[kcnt]=500000;
	scanf("%d",&n);
	m=sqrt(n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	scanf("%d",&ql);
	for(ri i=1;i<=ql;++i){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+ql+1);
	ri l=1,r=0;
	for(ri i=1;i<=ql;++i){
		while(l<q[i].l)del(a[l++]);
		while(l>q[i].l)add(a[--l]);
		while(r<q[i].r)add(a[++r]);
		while(r>q[i].r)del(a[r--]);
		ans[q[i].id]=query();
	}
	for(ri i=1;i<=ql;++i)printf("%d\n",ans[i]);
	return 0;
}