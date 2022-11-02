#include<cstdio>
typedef long long ll;
const int N=800002;
int n,q,i,j,k,a[N],h[N],t[N],v[N],x,y,z,X,Y,w,s[N],fa[N],f[N][20],e[N],d[N],dfn[N],P[N],Q[N],rv[N],T,top[N],rt=1,opt,O;
ll tr[N],lazy[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs1(int i){
	s[i]=1;
	for(int j=0;1<<(j+1)<=d[i];j++)
		f[i][j+1]=f[f[i][j]][j];
	for(int j=h[i];j;j=t[j]){
		if(v[j]!=fa[i]){
			d[v[j]]=d[i]+1;
			f[v[j]][0]=i;
			fa[v[j]]=i;
			dfs1(v[j]);
			s[i]+=s[v[j]];
			if(s[v[j]]>s[e[i]])
				e[i]=v[j];
		}
	}
}
void dfs2(int i){
	dfn[i]=P[i]=++T;
	rv[T]=i;
	if(e[i])
		top[e[i]]=top[i],dfs2(e[i]);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]&&v[j]!=e[i]){
			top[v[j]]=v[j];
			dfs2(v[j]);
		}
	Q[i]=T;
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]>d[top[y]])
			x=fa[top[x]];
		else
			y=fa[top[y]];
	}
	return d[x]<d[y]?x:y;
}
void Build(int rt,int l,int r){
	if(l==r)
		tr[rt]=a[rv[l]];
	else{
		int mid=l+r>>1;
		Build(rt<<1,l,mid);
		Build(rt<<1|1,mid+1,r);
		tr[rt]=tr[rt<<1]+tr[rt<<1|1];
	}
}
bool in(int x,int y){
	return P[x]<=P[y]&&Q[y]<=Q[x];
}
int anc(int x,int y){
	for(int i=20;i>=0;i--)
		if(y>>i&1)
			x=f[x][i],y-=(1<<i);
	return x;
}
void pushdown(int rt,int lm,int rm){
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		tr[rt<<1]+=1ll*lazy[rt]*lm;
		tr[rt<<1|1]+=1ll*lazy[rt]*rm;
		lazy[rt]=0;
	}
}
void Update(int rt,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		tr[rt]+=1ll*z*(r-l+1);
		lazy[rt]+=z;
		return;
	}
	int mid=l+r>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(x<=mid)
		Update(rt<<1,l,mid,x,y,z);
	if(mid<y)
		Update(rt<<1|1,mid+1,r,x,y,z);
	tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
ll Query(int rt,int l,int r,int x,int y){
	int mid=l+r>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(x<=l&&r<=y)	
		return tr[rt];
	ll ans=0;
	if(x<=mid)
		ans+=Query(rt<<1,l,mid,x,y);
	if(mid<y)
		ans+=Query(rt<<1|1,mid+1,r,x,y);
	tr[rt]=tr[rt<<1]+tr[rt<<1|1];
	return ans;
}
int max(int x,int y){
	return d[x]>d[y]?x:y;
}
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	Build(1,1,n);
	while(q--){
		scanf("%d",&opt);
		if(opt==1)
			scanf("%d",&rt);
		if(opt==2){
			scanf("%d%d%d",&x,&y,&O);
			z=LCA(x,y);
			if(z==rt||(in(rt,x)^in(rt,y)))
				Update(1,1,n,1,n,O);
			else{
				if(!in(z,rt)){
					Update(1,1,n,P[z],Q[z],O);
				}
				else{
					Update(1,1,n,1,n,O);
					z=max(max(LCA(x,rt),LCA(y,rt)),z);
					w=anc(rt,d[rt]-d[z]-1);
					Update(1,1,n,P[w],Q[w],-O);	
				}
			}
		}
		if(opt==3){
			scanf("%d",&x);
			if(x==rt)
				printf("%I64d\n",Query(1,1,n,1,n));
			else{
				if(!in(x,rt))
					printf("%I64d\n",Query(1,1,n,P[x],Q[x]));
				else{
					y=anc(rt,d[rt]-d[x]-1);
					printf("%I64d\n",Query(1,1,n,1,n)-Query(1,1,n,P[y],Q[y]));
				}
			}
		}
	}
}