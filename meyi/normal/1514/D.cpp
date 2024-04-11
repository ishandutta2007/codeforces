#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int a[maxn],ans[maxn],bel[maxn],cnt,lst[maxn],m,n,num[maxn],que[maxn],t,tp,vis[maxn];
struct qry{
	int l,r,id;
	inline bool operator<(const qry &k)const{
		return bel[l]!=bel[k.l]?l<k.l:r<k.r;
	}
}q[maxn];
inline int calc(int l,int r,int id){
	ri ret=0;
	for(ri i=l;i<=r;++i){
		if(vis[a[i]]!=id)lst[a[i]]=0,vis[a[i]]=id;
		ret=max(ret,++lst[a[i]]);
	}
	return max(ret*2-(r-l+1),1);
}
int main(){
	scanf("%d%d",&n,&t);
	m=sqrt(n);
	if(m==1)cnt=1;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	for(ri i=1;i<=t;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+t+1);
	for(ri i=1,j=1;j<=cnt;++j){
		ri R=min(j*m,n),pl=R+1,pr=R,len=0;
		for(;bel[q[i].l]==j;++i){
			if(bel[q[i].r]==j){
				ans[q[i].id]=calc(q[i].l,q[i].r,i);
				continue;
			}
			while(pr<q[i].r){
				++pr;
				if(!num[a[pr]]++)que[++tp]=a[pr];
				len=max(len,num[a[pr]]);
			}
			ri tmp=len;
			while(pl>q[i].l){
				--pl;
				++num[a[pl]];
				len=max(len,num[a[pl]]);
			}
			ans[q[i].id]=max(len*2-(q[i].r-q[i].l+1),1);
			while(pl<=R){
				--num[a[pl]];
				++pl;
			}
			len=tmp;
		}
		while(tp)num[que[tp--]]=0;
	}
	for(ri i=1;i<=t;++i)printf("%d\n",ans[i]);
}