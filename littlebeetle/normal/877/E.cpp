#include<cstdio>
const int N=800002;
int n,q,i,j,k;
int h[N],t[N],v[N],b[N],a[N],x;
int fa[N],sz[N],dfn[N],Tim;
int sum[N],lz[N],val[N];
char s[10];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs(int i){
	dfn[i]=++Tim;
	sz[i]=1;
	a[dfn[i]]=b[i];
	for(int j=h[i];j;j=t[j])
		dfs(v[j]),sz[i]+=sz[v[j]];
}
void Build(int rt,int l,int r){
	if(l==r){
		val[rt]=a[l];
		sum[rt]=1;
		return;
	}
	int mid=l+r>>1;
	Build(rt<<1,l,mid);
	Build(rt<<1|1,mid+1,r);
	val[rt]=val[rt<<1]+val[rt<<1|1];
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void init(){
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",fa+i);
		add(fa[i],i);
	}
	for(i=1;i<=n;i++)
		scanf("%d",b+i);
	dfs(1);
	Build(1,1,n);
}
void Change(int rt){
	val[rt]=sum[rt]-val[rt];
	lz[rt]^=1;
}
void Pushdown(int rt){
	if(lz[rt]){
		lz[rt]=0;
		Change(rt<<1);
		Change(rt<<1|1);
	}
}
void Pushup(int rt){
	val[rt]=val[rt<<1]+val[rt<<1|1];
}
void Update(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		Change(rt);
		return;
	}
	Pushdown(rt);
	int mid=l+r>>1;
	if(x<=mid)Update(rt<<1,l,mid,x,y);
	if(y>mid)Update(rt<<1|1,mid+1,r,x,y);
	Pushup(rt);
}
int Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y)
		return val[rt];
	Pushdown(rt);
	int mid=l+r>>1,s=0;
	if(x<=mid)s+=Query(rt<<1,l,mid,x,y);
	if(y>mid)s+=Query(rt<<1|1,mid+1,r,x,y);
	return s;	
}
void work(){
	scanf("%d",&q);
	while(q--){
		scanf("%s%d",s,&x);
		if(*s=='p')
			Update(1,1,n,dfn[x],dfn[x]+sz[x]-1);
		else
			printf("%d\n",Query(1,1,n,dfn[x],dfn[x]+sz[x]-1));
	}
}
int main(){
	init();
	work();
	return 0;
}