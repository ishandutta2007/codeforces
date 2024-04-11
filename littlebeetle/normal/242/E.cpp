#include<cstdio>
const int N=400002,K=21;
typedef long long ll;
int n,q,i,k,a[N],opt,x,y,z;
int sz[N][K],Sz[N],lz[N];
void Pushup(int rt){
	for(k=0;k<K;k++)
		sz[rt][k]=sz[rt<<1][k]+sz[rt<<1|1][k];
}
void Build(int rt,int l,int r){
	if(l==r){
		for(k=0;k<K;k++)
			sz[rt][k]=a[l]>>k&1;
		Sz[rt]=1;
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	Sz[rt]=Sz[rt<<1]+Sz[rt<<1|1];
	Pushup(rt);
}
void Change(int rt,int val){
	lz[rt]^=val;
	for(k=0;k<K;k++)
		if(val>>k&1)
			sz[rt][k]=Sz[rt]-sz[rt][k];
}
void Pushdown(int rt){
	if(lz[rt]){
		Change(rt<<1,lz[rt]);
		Change(rt<<1|1,lz[rt]);
		lz[rt]=0;
	}
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	Build(1,1,n);	
}
void Update(int rt,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		Change(rt,z);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)Update(rt<<1,l,mid,x,y,z);
	if(y>mid)Update(rt<<1|1,mid+1,r,x,y,z);
	Pushup(rt);
}
ll Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		ll s=0;
		for(k=0;k<K;k++)
			s+=(1ll<<k)*sz[rt][k];
		return s;
	}
	Pushdown(rt);
	ll s=0;
	int mid=l+r>>1;
	if(x<=mid)s+=Query(rt<<1,l,mid,x,y);
	if(y>mid)s+=Query(rt<<1|1,mid+1,r,x,y);
	return s;
}
void work(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&y);
			printf("%lld\n",Query(1,1,n,x,y));
		}
		else{
			scanf("%d%d%d",&x,&y,&z);
			Update(1,1,n,x,y,z);
		}
	}
}
int main(){
	init();
	work();
	return 0;
}