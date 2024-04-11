#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
typedef pair<int,int> pii;
#define fi first
#define se second
int ans[maxn],fa[maxn],son[maxn][2];
pii val[maxn],tag[maxn];
inline bool which(int p){
	return son[fa[p]][1]==p;
}
inline void connect(int p,int f,bool w){
	if(p)fa[p]=f;
	if(f)son[f][w]=p;
}
inline void add_tag(int p,pii v){
	if(p){
		val[p].fi-=v.fi,ans[val[p].se]+=v.se;
		tag[p].fi+=v.fi,tag[p].se+=v.se;
	}
}
inline void push_down(int p){
	if(tag[p]==pii{0,0})return;
	add_tag(son[p][0],tag[p]);
	add_tag(son[p][1],tag[p]);
	tag[p]={0,0};
}
inline void rotate(int p){
	ri f=fa[p],gf=fa[f];
	push_down(f),push_down(p);
	bool w=which(p),fw=which(f);
	connect(son[p][w^1],f,w);
	connect(f,p,w^1);
	connect(p,gf,fw);
}
int rt;
inline void splay(int p,int to){
	if(p){
		for(ri f;(f=fa[p])!=to;rotate(p))
			if(fa[f]!=to)
				rotate(which(f)==which(p)?f:p);
		if(!to)rt=p;
	}
}
int cnt,st[maxn],tp;
#define new_node (tp?st[tp--]:++cnt)
inline void insert(pii v){
	ri f=0,p=rt;
	bool w=0;
	while(p){
		push_down(p);
		f=p;
		w=(val[p]<v);
		p=son[p][w];
	}
	p=new_node;
	val[p]=v;
	connect(p,f,w);
	splay(p,0);
}
inline int find_le(int v){
	ri p=rt,ret=0;
	while(p){
		push_down(p);
		if(val[p].fi<v){
			ret=p;
			p=son[p][1];
		}
		else p=son[p][0];
	}
	if(ret)splay(ret,0);
	return ret;
}
inline int find_gr(int v){
	ri p=rt,ret=0;
	while(p){
		push_down(p);
		if(val[p].fi>v){
			ret=p;
			p=son[p][0];
		}
		else p=son[p][1];
	}
	if(ret)splay(ret,0);
	return ret;
}
vector<pii>tmp;
inline void recycle(int p,int f,bool w){
	if(!p)return;
	push_down(p);
	fa[p]=son[f][w]=0;
	st[++tp]=p;
	tmp.push_back(val[p]);
	recycle(son[p][0],p,0);
	recycle(son[p][1],p,1);
	son[p][0]=son[p][1]=0;
}
inline void query(int p){
	if(!p)return;
	push_down(p);
	query(son[p][0]);
	query(son[p][1]);
}
int c[maxn],id[maxn],m,n,q[maxn];
int main(){
	scanf("%d",&m);
	for(ri i=1;i<=m;++i)scanf("%d%d",c+i,q+i),id[i]=i;
	sort(id+1,id+m+1,[&](const int &x,const int &y){return q[x]!=q[y]?q[x]>q[y]:c[x]<c[y];});
	scanf("%d",&n);
	insert({INT_MIN,0});
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		insert({x,i});
	}
	insert({INT_MAX,n+1});
	for(ri j=1;j<=m;++j){
		ri i=id[j];
		ri x=find_le(c[i]),y=find_gr(2*c[i]-1);
		if(x!=y){
			splay(x,0),splay(y,x);
			add_tag(son[y][0],{c[i],1});
			recycle(son[y][0],y,0);
			for(const pii &k:tmp)insert(k);
			tmp={};
		}
		x=find_le(2*c[i]),y=find_gr(INT_MAX^1);
		if(x!=y){
			splay(x,0),splay(y,x);
			add_tag(son[y][0],{c[i],1});
		}
	}
	query(rt);
	for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}