#include<cstdio>
const int N=2000002;
int n,m,i,j,k,a,b,h[N],v[N],t[N],id[N],rid[N],sz[N],C[N],T,opt,x,cl;
long long c[N],p[N],ans;
void dfs(int i,int fa){
	id[i]=++T;
	rid[T]=i;
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			sz[i]+=sz[v[j]];
		}
}
void Build(int rt,int l,int r){
	if(l==r)
		c[rt]=1ll<<C[rid[l]];
	else{
		int mid=l+r>>1;
		Build(rt<<1,l,mid);
		Build(rt<<1|1,mid+1,r);
		c[rt]=c[rt<<1]|c[rt<<1|1];
	}
}
void Update(int rt,int l,int r,int x,int y,int C){
	if(x<=l&&r<=y){
		c[rt]=p[rt]=1ll<<C;
		return;
	}
	if(p[rt]){
		p[rt<<1]=p[rt<<1|1]=c[rt<<1]=c[rt<<1|1]=p[rt];
		p[rt]=0;
	}
	int mid=l+r>>1;
	if(x<=mid)
		Update(rt<<1,l,mid,x,y,C);
	if(y>mid)
		Update(rt<<1|1,mid+1,r,x,y,C);
	c[rt]=c[rt<<1]|c[rt<<1|1];
}
void Query(int rt,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		ans|=c[rt];
		return;
	}
	if(p[rt]){
		p[rt<<1]=p[rt<<1|1]=c[rt<<1]=c[rt<<1|1]=p[rt];
		p[rt]=0;
	}
	int mid=l+r>>1;
	if(x<=mid)
		Query(rt<<1,l,mid,x,y);
	if(y>mid)
		Query(rt<<1|1,mid+1,r,x,y);
	c[rt]=c[rt<<1]|c[rt<<1|1];
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",C+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	Build(1,1,n);
	while(m--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&cl);
			Update(1,1,n,id[x],id[x]+sz[x]-1,cl);
		}
		else{
			scanf("%d",&x);
			ans=0;
			Query(1,1,n,id[x],id[x]+sz[x]-1);
			x=0;
			while(ans)
				ans&=ans-1,x++;
			printf("%d\n",x);
		}
	}
}