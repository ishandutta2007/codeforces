#include<bits/stdc++.h>
#define abs(x) ((x)<0?-(x):(x))
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=233333,K=6,B=33,T=N<<2,INF=0x3f3f3f3f3f3f3f3fll,NINF=-0x3f3f3f3f3f3f3f3fll;
int n,k,q,cood[N][K],ans[N],mx[T][B],mn[T][B],tmx[B],tmn[B];
inline int read(){
	int x=0,flg=1;
	char c=getchar();
	while(!isdigit(c))flg=(c=='-'?-flg:flg),c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*flg;
}
inline void update(int x){
	for(int i=0;i<1<<k;i++)
		mx[x][i]=max(mx[ls(x)][i],mx[rs(x)][i]),
		mn[x][i]=min(mn[ls(x)][i],mn[rs(x)][i]);
}
inline void initnode(int x,int p){
	for(int i=0;i<1<<k;i++){
		mx[x][i]=mn[x][i]=0;
		for(int j=1;j<=k;j++)
			mx[x][i]=(mn[x][i]+=((i>>(j-1))&1?1:-1)*cood[p][j]);
	}
}
inline void build(int x,int l,int r){
	if(l==r){initnode(x,l);return;}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
inline void modify(int x,int l,int r,int p){
	if(l==r){initnode(x,l);return;}
	int mid=(l+r)>>1;
	if(p>mid)modify(rs(x),mid+1,r,p);
	else modify(ls(x),l,mid,p);
	update(x);
}
inline void query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		for(int i=0;i<1<<k;i++)
			tmx[i]=max(tmx[i],mx[x][i]),tmn[i]=min(tmn[i],mn[x][i]);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)query(ls(x),l,mid,ql,qr);
	if(qr>mid)query(rs(x),mid+1,r,ql,qr);
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)cood[i][j]=read();
	build(1,1,n);
	q=read();
	while(q--){
		int op=read(),x,l,r;
		if(op==1){
			x=read();
			for(int i=1;i<=k;i++)cood[x][i]=read();
			modify(1,1,n,x);
		}else{
			l=read();r=read();
			memset(tmx,NINF,sizeof tmx);
			memset(tmn,INF,sizeof tmn);
			query(1,1,n,l,r);
			int ans=NINF;
			for(int i=0;i<1<<k;i++)
				ans=max(ans,tmx[i]-tmn[i]);
			printf("%lld\n",ans);
		}
	}
}