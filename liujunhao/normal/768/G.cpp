#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
#define pb push_back
#define all(a) a.begin(),a.end()
#define pointtype double
#define pointtype_INT 0
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
struct point{
	pointtype x,y;
	inline point(){
	}
	inline point(pointtype x,pointtype y=0):x(x),y(y){
	}
	inline point operator+(const point &a)const{
		return point(x+a.x,y+a.y);
	}
	inline point operator+=(const point &a){
		return *this=*this+a;
	}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
	}
	inline point operator-=(const point &a){
		return *this=*this-a;
	}
	inline bool operator<(const point &b)const{
		if(x==b.x)
			return y<b.y;
		return x<b.x;
	}
	inline bool operator==(const point &b)const{
		return x==b.x&&y==b.y;
	}
	#if pointtype_INT==1
		inline point operator*(const point &a)const{
			return point(1ll*x*a.x-1ll*y*a.y,1ll*x*a.y+1ll*y*a.x);
		}
		inline friend LL cross(const point &a,const point &b){
			return 1ll*a.x*b.y-1ll*a.y*b.x;
		}
		inline friend LL dot(const point &a,const point &b){
			return 1ll*a.x*b.x+1ll*a.y*b.y;
		}
	#else
		inline point operator*(const point &a)const{
			return point(x*a.x-y*a.y,x*a.y+y*a.x);
		}
		inline friend pointtype cross(const point &a,const point &b){
			return a.x*b.y-a.y*b.x;
		}
		inline friend pointtype dot(const point &a,const point &b){
			return a.x*b.x+a.y*b.y;
		}
	#endif
};
template<class T,class T2>
struct hashnode{
	T val;
	T2 v;
	hashnode *next;
};
template<class T,class T2>
inline int& addhash(int u,const T &val,T2 *&ecnt,T2 **adj){
	T2 *p=++ecnt;
	p->val=val;
	p->v=0;
	p->next=adj[u];
	adj[u]=p;
	return p->v;
}
template<class T,class T2,int MOD,int ss>
class hash_table{
	hashnode<T,T2>*adj[MOD],edge[ss+10],*ecnt;
	int sz;
	public:
	inline int Get_val(int x){
		return x%MOD;
	}
	#if pointtype_INT==1
		inline int Get_val(point x){
			return (x.x*998244353ll+x.y)%MOD;
		}
	#endif
	inline hash_table():ecnt(edge),sz(0){
		for(int i=0;i<MOD;i++)
			adj[i]=0;
	}
	inline int size(){
		return sz;
	}
	inline hashnode<T,T2>* hash(const T &x){
		int t=Get_val(x);
		for(hashnode<T,T2> *p=adj[t];p;p=p->next)
			if(p->val==x)
				return p;
		return 0;
	}
	inline int &operator[](const T &x){
		hashnode<T,T2> *p=hash(x);
		if(p)
			return p->v;
		return ++sz,addhash(Get_val(x)%MOD,x,ecnt,adj);
	}
	inline bool count(const T &x){
		return hash(x);
	}
	inline void clear(){
		ecnt=edge;
		int t=MOD>>2<<2,i;
		for(i=0;i<t;i+=4){
			adj[i]=0;
			adj[i+1]=0;
			adj[i+2]=0;
			adj[i+3]=0;
		}
		for(;i<MOD;i++)
			adj[i]=0;
		sz=0;
	}
};
template<class T,int len>
struct polynomial{
	T a[len];
	inline void clear(){
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			a[i]=0;
			a[i+1]=0;
			a[i+2]=0;
			a[i+3]=0;
		}
		for(;i<len;i++)
			a[i]=0;
	}
	inline polynomial operator+(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]+b.a[i];
			c.a[i+1]=a[i+1]+b.a[i+1];
			c.a[i+2]=a[i+2]+b.a[i+2];
			c.a[i+3]=a[i+3]+b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]+b.a[i];
		return c;
	}
	inline polynomial operator+=(const polynomial &b){
		return *this=*this+b;
	}
	inline polynomial operator-(const polynomial &b)const{
		static polynomial c;
		int t=len>>2<<2,i;
		for(i=0;i<t;i+=4){
			c.a[i]=a[i]-b.a[i];
			c.a[i+1]=a[i+1]-b.a[i+1];
			c.a[i+2]=a[i+2]-b.a[i+2];
			c.a[i+3]=a[i+3]-b.a[i+3];
		}
		for(;i<len;i++)
			c.a[i]=a[i]-b.a[i];
		return c;
	}
	inline polynomial operator-=(const polynomial &b){
		return *this=*this-b;
	}
};
//template
#define MAXN 100000
vector<int>g[MAXN+10];
multiset<int>tot,s,par;
int rt,n,size[MAXN+10],ans[MAXN+10];
void read(){
	Read(n);
	int i,u,v;
	for(i=1;i<=n;i++){
		Read(u),Read(v);
		if(!u)
			rt=v;
		else
			g[u].pb(v);
	}
}
void dfs(int u){
	size[u]=1;
	for(auto v:g[u]){
		dfs(v);
		size[u]+=size[v];
	}
	tot.insert(size[u]);
}
void add(int u){
	s.insert(size[u]);
	tot.erase(tot.find(size[u]));
	for(auto v:g[u])
		add(v);
}
void del(int u){
	s.erase(s.find(size[u]));
	tot.insert(size[u]);
	for(auto v:g[u])
		del(v);
}
void dfs2(int u,bool rm){
	tot.erase(tot.find(size[u]));
	int heavy(0),mi=0x7fffffff,se=0;
	for(auto v:g[u]){
		if(size[v]>size[heavy]){
			se=size[heavy];
			heavy=v;
		}
		else if(size[v]>se)
			se=size[v];
		mi=min(mi,size[v]);
	}
	par.insert(size[u]);
	for(auto v:g[u])
		if(v!=heavy)
			dfs2(v,0);
	if(heavy)
		dfs2(heavy,1);
	if(u!=rt)
		mi=min(mi,n-size[u]);
	if(n-size[u]<=size[heavy]){
		se=max(se,n-size[u]);
		ans[u]=size[heavy];
		if(size[heavy]!=mi){
			int t=(size[heavy]-mi)/2;
			s.erase(size[heavy]);
			auto l=s.lower_bound(t);
			if(l!=tot.end())
				ans[u]=min(ans[u],max(max(size[heavy]-*l,mi+*l),se));
			if(l--!=tot.begin())
				ans[u]=min(ans[u],max(max(size[heavy]-*l,mi+*l),se));
			s.insert(size[heavy]);
		}
	}
	for(auto v:g[u])
		if(v!=heavy)
			add(v);
	
	if(n-size[u]>size[heavy]){
		se=size[heavy];
		ans[u]=n-size[u];
		if(n-size[u]!=mi){
			int t=(n-size[u]-mi)/2;
			auto l=tot.lower_bound(t);
			if(l!=tot.end())
				ans[u]=min(ans[u],max(max(n-size[u]-*l,mi+*l),se));
			if(l--!=tot.begin())
				ans[u]=min(ans[u],max(max(n-size[u]-*l,mi+*l),se));
			par.erase(n);
			l=par.lower_bound(t+size[u]);
			if(l!=par.end())
				ans[u]=min(ans[u],max(max(n-size[u]-(*l-size[u]),(*l-size[u])+mi),se));
			if(l--!=par.begin())
				ans[u]=min(ans[u],max(max(n-size[u]-(*l-size[u]),(*l-size[u])+mi),se));
			par.insert(n);
		}
	}
	s.insert(size[u]);
	if(!rm)
		del(u);
	par.erase(par.find(size[u]));
}
void solve(){
	dfs(rt);
	dfs2(rt,1);
}
void print(){
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	read();
	if(n==1){
		puts("0");
		return 0;
	}
	solve();
	print();
}