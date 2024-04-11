#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<string>
#include<iostream>
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
pii a[MAXN*2+10];
int n,m,d[MAXN+10],cnt,tp,b[MAXN+10],st[MAXN+10],size[MAXN+10],mxs[MAXN+10],col[MAXN+10],rt,pos[MAXN+10];
bool vis[MAXN+10];
vector<int>pt[MAXN+10],g[MAXN+10];
void find_center(int u,int fa,int tot,int &heavy){
	size[u]=1;
	mxs[u]=0;
	for(auto v:g[u]){
		if(!col[v]&&v!=fa){
			find_center(v,u,tot,heavy);
			size[u]+=size[v];
			mxs[u]=max(mxs[u],size[v]);
		}
	}
	mxs[u]=max(mxs[u],tot-size[u]);
	if(mxs[u]<mxs[heavy])
		heavy=u;
}
void solve(int u,int tot,int c){
	int heavy(0);
	find_center(u,0,tot,heavy);
	col[heavy]=c;
	c++;
	for(auto v:g[heavy]){
		if(!col[v]){
			if(size[v]>size[heavy])
				solve(v,tot-size[heavy],c);
			else
				solve(v,size[v],c);
		}
	}
}
int main()
{
	Read(n),Read(m);
	int i,x,y,j;
	for(i=1;i<=m;i++){
		Read(x),Read(y);
		if(x>y)
			swap(x,y);
		if(y-x>n/2)
			swap(x,y);
		a[i]=pii(x,y);
		a[i+m]=pii(y,x);
		if(x<y)
			d[x+1]++,d[y]--;
		else
			d[x+1]++,d[1]++,d[y]--;
	}
	m*=2;
	for(i=1;i<=n;i++){
		d[i]+=d[i-1];
		if(!d[i]){
			rt=i;
			break;
		}
	}
	j=rt;
	do{
		pos[j]=++cnt;
		if(++j>n)
			j=1;
	}while(j!=rt);
	sort(a+1,a+m+1,[](auto x,auto y){return x.first==y.first?pos[x.second]<pos[y.second]:pos[x.first]<pos[y.first];});
	st[tp=1]=cnt=1;
	i=rt;
	j=1;
	do{
		pt[st[tp]].pb(i);
		for(;j<=m&&a[j].first==i;j++){
			if(pos[a[j].second]>pos[a[j].first]){
				g[st[tp]].pb(++cnt);
				g[cnt].pb(st[tp]);
				st[++tp]=cnt;
				pt[cnt].pb(i);
			}
			else{
				g[st[tp]].pb(st[tp-1]);
				g[st[tp-1]].pb(st[tp]);
				tp--;
				pt[st[tp]].pb(i);
			}
		}
		if(++i>n)
			i=1;
	}while(i!=rt);
	for(i=1;i<=cnt;i++){
		sort(all(pt[i]),greater<int>());
		b[i]=i;
	}
	for(i=1;i<=n;i++){
		sort(all(g[i]));
		g[i].erase(unique(all(g[i])),g[i].end());
	}
	mxs[0]=0x7fffffff;
	solve(1,n,1);
	sort(b+1,b+cnt+1,[](int x,int y){return pt[x]<pt[y];});
	for(i=1;i<=cnt;i++)
		printf("%d ",col[b[i]]);
}