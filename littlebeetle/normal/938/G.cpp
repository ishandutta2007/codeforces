#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=800020;
int n,m,q,T,a,b,c,A[N],B[N],i;
int sz[N],st[N*20],top,gp[N*20],fa[N],dis[N];
int opt,Ans[N];
struct Uzi{
	int a,b,c,d,o;
	bool operator<(const Uzi &k)const{
		if(k.a!=a)
			return k.a>a;
		if(k.b!=b)
			return k.b>b;
			return k.o>o;
	}
}e[N];
struct EDG{
	int a,b,c;
};
vector<EDG>g[N];
void swap(int &a,int &b){
	int t=a;a=b;b=t;
}
void Update(int rt,int l,int r,int x,int y,int a,int b,int c){
	if(x<=l&&r<=y){
		g[rt].push_back((EDG){a,b,c});
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		Update(rt<<1,l,mid,x,y,a,b,c);
	if(y>mid)
		Update(rt<<1|1,mid+1,r,x,y,a,b,c);
}
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)
			swap(a,b);
		e[i]=(Uzi){a,b,c,1,0};
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&a,&b,&c);
			if(a>b)
				swap(a,b);
			e[++m]=(Uzi){a,b,c,T+1,i};
		}
		if(opt==2){
			scanf("%d%d",&a,&b);
			if(a>b)
				swap(a,b);
			e[++m]=(Uzi){a,b,0,T,i};
		}
		if(opt==3){
			T++;
			scanf("%d%d",A+T,B+T);
		}
	}
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++)
		if(e[i].a==e[i+1].a&&e[i].b==e[i+1].b){
			//printf("%d %d %d %d\n",e[i].a,e[i].b,e[i].d,min(T,e[i+1].d));
			if(e[i].d<=T&&e[i].d<=e[i+1].d)
			Update(1,1,T,e[i].d,min(T,e[i+1].d),e[i].a,e[i].b,e[i].c);
			i++;
		}
		else
			if(e[i].d<=T){
				//printf("%d %d %d %d\n",e[i].a,e[i].b,e[i].d,T);
				Update(1,1,T,e[i].d,T,e[i].a,e[i].b,e[i].c);
			}
	for(i=1;i<=n;i++)
		fa[i]=i,sz[i]=1;
}
struct xxj{
	int f[31];
	void insert(int x){
		for(int k=30;k>=0;k--)
			if(x>>k&1){
				if(f[k])
					x^=f[k];
				else{
					f[k]=x;
					break;
				}
			}
	}
	int search(int x){
		for(int k=30;k>=0;k--)
			if(x>>k&1)
				if(f[k])
					x^=f[k];
		return x;
	}
}P[30];
int anc(int x){
	return x==fa[x]?x:anc(fa[x]);
}
int dep(int x){
	return x==fa[x]?0:(dis[x]^dep(fa[x]));
}
void merge(int a,int b,int c,int id){
	c^=dep(a)^dep(b);
	if(anc(a)==anc(b))
		P[id].insert(c);
	else{
		a=anc(a);
		b=anc(b);
		if(sz[a]>sz[b])
			swap(a,b);
		sz[b]+=sz[a];
		fa[a]=b;
		dis[a]=c;
		st[++top]=a;
		gp[top]=id;
	}
}
void Del(int id){
	while(top&&gp[top]==id){
		int a=st[top--];
		sz[fa[a]]-=sz[a];
		fa[a]=a;
	}
}
void Work(int rt,int l,int r,int de){

	for(int j=0;j<g[rt].size();j++)
		merge(g[rt][j].a,g[rt][j].b,g[rt][j].c,de);
	if(l==r){
		Ans[l]=P[de].search(dep(A[l])^dep(B[l]));
		Del(de);
		return;
	}
	int mid=l+r>>1;
	P[de+1]=P[de];
	Work(rt<<1,l,mid,de+1);
	P[de+1]=P[de];
	Work(rt<<1|1,mid+1,r,de+1);
	Del(de);
}
int main(){
	init();
	Work(1,1,T,0);
	for(i=1;i<=T;i++)
		printf("%d\n",Ans[i]);
	//while(1);
}