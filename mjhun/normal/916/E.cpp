#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll st[1<<18],lazy[1<<18];
void st_init(int k, int s, int e, int *a){
	if(s+1==e)st[k]=a[s];
	else {
		int m=(s+e)/2;
		st_init(2*k,s,m,a);st_init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1];
	}
}
void st_push(int k, int s, int e){
	if(!lazy[k])return;
	st[k]+=(e-s)*lazy[k];
	if(e-s>1){
		lazy[2*k]+=lazy[k];
		lazy[2*k+1]+=lazy[k];
	}
	lazy[k]=0;
}
void st_upd(int k, int s, int e, int a, int b, int v){
	st_push(k,s,e);
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b){
		lazy[k]+=v;
		st_push(k,s,e);
		return;
	}
	int m=(s+e)/2;
	st_upd(2*k,s,m,a,b,v);st_upd(2*k+1,m,e,a,b,v);
	st[k]=st[2*k]+st[2*k+1];
}
ll st_query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return 0;
	st_push(k,s,e);
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return st_query(2*k,s,m,a,b)+st_query(2*k+1,m,e,a,b);
}

#define K 17

int n,q,r;
vector<int> g[1<<K];
int d[1<<K],f[K][1<<K],a[1<<K],b[1<<K],T;

void dfs(int x){
	a[x]=T++;
	for(int y:g[x]){
		if(y==f[0][x])continue;
		d[y]=d[x]+1;f[0][y]=x;
		dfs(y);
	}
	b[x]=T;
}
void init(){
	f[0][0]=-1;dfs(0);
	fore(k,1,K)fore(i,0,n){
		if(f[k-1][i]<0)f[k][i]=-1;
		else f[k][i]=f[k-1][f[k-1][i]];
	}
}
int lca(int x, int y){
	if(d[x]<d[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(d[x]-(1<<k)>=d[y])x=f[k][x];
	assert(d[x]==d[y]);
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(f[k][x]!=f[k][y])x=f[k][x],y=f[k][y];
	assert(x!=y&&f[0][x]==f[0][y]);
	return f[0][x];
}
int dist(int x, int y){
	int z=lca(x,y);
	return d[x]+d[y]-2*d[z];
}
int dem(int x, int y){
	for(int k=K-1;k>=0;--k)if(d[x]-(1<<k)>d[y])x=f[k][x];
	assert(f[0][x]==y);
	return x;
}
bool bet(int x, int y, int z){return dist(x,z)+dist(y,z)==dist(x,y);}

int w[1<<K],ww[1<<K];

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n)scanf("%d",w+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	init();
	fore(i,0,n)ww[a[i]]=w[i];
	st_init(1,0,n,ww);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1)scanf("%d",&r),r--;
		else if(t==2){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);x--;y--;
			int z=lca(x,y);
			if(bet(x,r,z))swap(x,y);
			assert(bet(y,r,z));
			if(!bet(y,r,x)){
				for(int k=K-1;k>=0;--k)if(d[x]-(1<<k)>d[z]&&!bet(y,r,f[k][x]))x=f[k][x];
				assert(!bet(y,r,x)&&bet(y,r,f[0][x]));
				x=f[0][x];
			}
			if(x==r)st_upd(1,0,n,0,n,v);
			else {
				int z=lca(x,r);
				if(z==x){
					z=dem(r,x);st_upd(1,0,n,0,n,v);
					st_upd(1,0,n,a[z],b[z],-v);
				}
				else st_upd(1,0,n,a[x],b[x],v);
			}
		}
		else {
			int x;
			scanf("%d",&x);x--;
			if(x==r){st_push(1,0,n);printf("%lld\n",st[1]);}
			else {
				int z=lca(x,r);
				if(z==x){
					z=dem(r,x);st_push(1,0,n);
					printf("%lld\n",st[1]-st_query(1,0,n,a[z],b[z]));
				}
				else printf("%lld\n",st_query(1,0,n,a[x],b[x]));
			}
		}
	}
	return 0;
}