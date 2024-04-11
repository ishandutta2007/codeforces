#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,maxp=321;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int bel[maxn],cnt,fa[maxn],m,n,pre[maxn],q;
struct block{
	int kl,kr;
	ll sum,tag;
	inline void build(){
		for(ri i=kl;i<=kr;++i){
			pre[i]=fa[i];
			while(pre[i]>=kl)pre[i]=pre[pre[i]];
		}
	}
}b[maxp];
inline void modify(int l,int r,int v){
	ri L=bel[l],R=bel[r];
	if(L==R){
		for(ri i=l;i<=r;++i)fa[i]=max(fa[i]-v,1);
		b[L].build();
		return;
	}
	for(ri i=L+1;i<R;++i){
		b[i].sum+=v;
		if(b[i].sum>m)b[i].tag+=v;
		else{
			for(ri j=b[i].kl;j<=b[i].kr;++j)fa[j]=max(fa[j]-v,1);
			b[i].build();
		}
	}
	for(ri i=l;i<=b[L].kr;++i)fa[i]=max(fa[i]-v,1);
	b[L].build();
	for(ri i=b[R].kl;i<=r;++i)fa[i]=max(fa[i]-v,1);
	b[R].build();
}
inline int getfa(int k){
	return max(fa[k]-b[bel[k]].tag,1ll);
}
inline int getpre(int k){
	return b[bel[k]].sum>m?getfa(k):pre[k];
}
inline int lca(int x,int y){
	while(getpre(x)!=getpre(y)){
		if(bel[x]!=bel[y]){
			if(bel[x]<bel[y])swap(x,y);
			x=getpre(x);
		}
		else x=getpre(x),y=getpre(y);
	}
	while(x!=y){
		if(x<y)swap(x,y);
		x=getfa(x);
	}
	return x;
}
int main(){
	scanf("%d%d",&n,&q);
	m=max(2,(int)sqrt(n));
	for(ri i=1;i<=n;++i){
		if(i%m==1)b[cnt].kr=i-1,b[++cnt].kl=i;
		bel[i]=cnt;
	}
	b[cnt].kr=n;
	for(ri i=2;i<=n;++i)scanf("%d",fa+i);
	for(ri i=1;i<=cnt;++i)b[i].build();
	while(q--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op&1){
			scanf("%d",&z);
			modify(x,y,z);
		}
		else printf("%d\n",lca(x,y));
	}
	return 0;
}