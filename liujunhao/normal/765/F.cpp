#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
#define pointtype int
#define pointtype_INT 1
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
	inline point(pointtype x,pointtype y):x(x),y(y){
	}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
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
	inline int Get_val(point x){
		return (x.x*998244353ll+x.y)%MOD;
	}
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
//template
#define MAXN 100000
#define MAXM 300000
int n,m,a[MAXN+10],ans[MAXM+10];
struct Query{
	int l,r,pos;
	inline Query(){
	}
	inline Query(int l,int r,int pos):l(l),r(r),pos(pos){
	}
	inline bool operator <(const Query &a)const{
		return l<a.l;
	}
}q[MAXM+10];
struct node{
	int mi;
	set<int>s;
}tree[MAXN*4+10];
void build(int i,int l,int r){
	tree[i].mi=0x7fffffff;
	for(int j=l;j<=r;j++)
		tree[i].s.insert(a[j]);
	if(l==r)
		return;
	int mid((l+r)>>1);
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}
int get_mi(int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i].mi;
	if(ll>r||rr<l)
		return 0x7fffffff;
	int mid((l+r)>>1);
	return min(get_mi(i<<1,l,mid,ll,rr),get_mi((i<<1)|1,mid+1,r,ll,rr));
}
void modify(int i,int l,int r,int ll,int rr,int &mi,int x){
	if(ll>r||rr<l)
		return;
	if(l==r){
		mi=min(mi,tree[i].mi=min(tree[i].mi,abs(x-a[l])));
		return;
	}
	auto j=tree[i].s.lower_bound(x);
	if((j==tree[i].s.end()||*j-x>=mi)&&(j==tree[i].s.begin()||x-*--j>=mi)){
		mi=min(mi,get_mi(i,l,r,ll,rr));
		return;
	}
	int mid((l+r)>>1);
	modify(i<<1,l,mid,ll,rr,mi,x);
	modify((i<<1)|1,mid+1,r,ll,rr,mi,x);
	tree[i].mi=min(tree[i<<1].mi,tree[(i<<1)|1].mi);
}
void read(){
	Read(n);
	int i,l,r;
	for(i=1;i<=n;i++)
		Read(a[i]);
	Read(m);
	for(i=1;i<=m;i++){
		Read(l),Read(r);
		q[i]=Query(l,r,i);
	}
	sort(q+1,q+m+1);
}
void solve(){
	build(1,1,n);
	int i,l,t;
	for(i=m,l=n;i;i--){
		while(l>=q[i].l){
			modify(1,1,n,l+1,n,t=0x7fffffff,a[l]);
			--l;
		}
		ans[q[i].pos]=get_mi(1,1,n,q[i].l,q[i].r);
	}
}
void print(){
	int i;
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
int main()
{
	read();
	solve();
	print();
}