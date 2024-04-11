#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,maxp=510;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll a[maxn],add[maxn],pre[maxn];
int bel[maxn],cnt,fr[maxn],id[maxn],lim,m,n,pos[maxn],siz[maxn],to[maxn],tmp[maxp<<1][maxp<<1],x[maxn],y[maxn],z[maxn];
inline void solve(){
	for(ri i=1;i<=n;++i)add[i]=bel[i]=id[i]=pos[i]=siz[i]=0,pre[i]=pre[i-1]+a[i];
	for(ri i=1;i<=cnt;++i)
		if(x[i]>1){
			bel[y[i]]=y[i];
			if(x[i]==3)bel[z[i]]=z[i];
		}
	ri tot=0;
	for(ri i=1;i<=n;++i)
		if(bel[i]==i){
			for(ri j=i;;){
				bel[j]=i;
				j=fr[j];
				if(bel[j])break;
			}
			pos[++tot]=i;
		}
	ri gid=0;
	id[0]=0;
	for(ri i=1;i<=cnt;++i)
		if(x[i]==1){
			if(!id[y[i]-1])id[y[i]-1]=++gid;
			if(!id[z[i]])id[z[i]]=++gid;
		}
	if(id[0])
		for(ri i=1;i<=tot;++i)
			tmp[i][id[0]]=0;
	for(ri i=1;i<=n;++i){
		++siz[bel[i]];
		if(id[i])
			for(ri j=1;j<=tot;++j)
				tmp[j][id[i]]=siz[pos[j]];
	}
	for(ri i=1;i<=cnt;++i){
		if(x[i]==1){
			ll ans=pre[z[i]]-pre[y[i]-1];
			for(ri j=1;j<=tot;++j)ans+=add[pos[j]]*(tmp[j][id[z[i]]]-tmp[j][id[y[i]-1]]);
			printf("%lld\n",ans);
		}
		if(x[i]==2){
			for(ri j=y[i];;){
				add[j]+=z[i];
				j=bel[to[j]];
				if(j==y[i])break;
			}
		}
		if(x[i]==3){
			swap(to[y[i]],to[z[i]]);
			fr[to[y[i]]]=y[i],fr[to[z[i]]]=z[i];
		}
	}
	for(ri i=1;i<=n;++i)a[i]+=add[bel[i]];
	cnt=0;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	for(ri i=1;i<=n;++i)scanf("%d",to+i),fr[to[i]]=i;
	scanf("%d",&m);
	lim=sqrt(m);
	while(m--){
		++cnt;
		scanf("%d%d%d",x+cnt,y+cnt,z+cnt);
		if(cnt%lim==0)solve();
	}
	if(cnt)solve();
	return 0;
}