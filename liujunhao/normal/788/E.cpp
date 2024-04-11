#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<cassert>
#include<map>
#include<string>
#include<iostream>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
#include<bitset>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
#define pb push_back
#define all(a) a.begin(),a.end()
#define pointtype double
#define pointtype_INT 0
using namespace std;
using namespace tr1;
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
template<int sz,int MOD>
struct Matrix{
	int a[sz][sz];
	inline Matrix(){
		memset(a,0,sizeof a);
	}
	inline Matrix(int){
		memset(a,0,sizeof a);
		for(int i=0;i<sz;i++)
			a[i][i]=1;
	}
	inline Matrix operator *(const Matrix &b)const{
		static Matrix c;
		c.clear();
		int i,j,k;
		for(i=0;i<sz;i++)
			for(j=0;j<sz;j++)
				if(a[i][j])
					for(k=0;k<sz;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%MOD;
		return c;
	}
	inline Matrix &operator *=(const Matrix &b){
		return *this=*this*b;
	}
	friend Matrix quick_pow(Matrix a,int b){
		Matrix ret(1);
		while(b){
			if(b&1)
				ret*=a;
			a*=a;
			b>>=1;
		}
		return ret;
	}
};
struct cpx{
	double r,i;
	inline cpx(){
	}
	inline cpx(double r,double i):r(r),i(i){
	}
	inline cpx operator+(const cpx &a)const{
		return cpx(r+a.r,i+a.i);
	}
	inline cpx operator-(const cpx &a)const{
		return cpx(r-a.r,i-a.i);
	}
	inline cpx operator*(const cpx &a)const{
		return cpx(r*a.r-i*a.i,r*a.i+i*a.r);
	}
	inline cpx operator/(const double &a)const{
		return cpx(r/a,i/a);
	}
	inline cpx operator/(const cpx&a)const{
		return *this*cpx(a.r,-a.i)/(a.r*a.r+a.i*a.i);
	}
	inline cpx operator+=(const cpx &a){
		return *this=*this+a;
	}
	inline cpx operator-=(const cpx &a){
		return *this=*this-a;
	}
	inline cpx operator*=(const cpx &a){
		return *this=*this*a;
	}
	inline cpx operator/=(const cpx &a){
		return *this=*this/a;
	}
	inline cpx conj(){
		return cpx(r,-i);
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
	inline polynomial operator*(const polynomial &b){
		static polynomial ret;
		ret.clear();
		for(int i=0;i<len;i++)
			for(int j=0;j<=i;j++)
				ret.a[i]+=a[j]*b.a[i-j];
		return ret;
	}
	inline void Antiderivative(int c){
		int i;
		for(i=len-1;i;i--)
			a[i]=a[i-1]/i;
		a[0]=c;
	}
	inline T Get_val(T c){
		T ret(a[0]);
		for(int i=1;i<len;i++){
			ret+=c*a[i];
			c*=c;
		}
		return ret;
	}
};
void fft(cpx *a,int N,int f){
	int i,j=0,k,t;
	for(i=1;i<N-1;i++){
		for(t=N;j^=t>>=1,~j&t;);
		if(i<j)
			swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		cpx wn(cos(pi/i),f*sin(pi/i));
		t=i<<1;
		for(j=0;j<N;j+=t){
			cpx w(1,0);
			for(k=0;k<i;k++,w*=wn){
				cpx x(a[j+k]),y(w*a[j+k+i]);
				a[j+k]=x+y,a[j+k+i]=x-y;
			}
		}
	}
	if(f==-1)
		for(i=0;i<N;i++)
			a[i].r/=N;
}
void mul(cpx *a,cpx *b,cpx *c,cpx *t,int N){
	int i,j;
	for(i=0;i<N;i++)
		t[i]=cpx(a[i].r,b[i].r);
	fft(t,N,1);
	for(i=0;i<N;i++){
		j=(N-i)&(N-1);
		c[i]=(t[i]*t[i]-(t[j]*t[j]).conj())*cpx(0,-0.25);
	}
	fft(c,N,-1);
	// c refer t
	//a[i]=(c[i]+c[k-i])/2
	//b[i]=-i(c[i]-c[k-i])/2
	//a[i]*b[i]=(c[i]*c[i]-c[k-i]*c[k-i])*((-i)/4)
}
//template
#define MAXN 100000
#define MOD 1000000007
int c[MAXN+10],pos[MAXN+10],rcnt,r[MAXN+10],n,a[MAXN+10],ans,Q;
inline int lowbit(int x){
	return x&-x;
}
inline void update(int x,int d){
	while(x<=rcnt){
		c[x]+=d;
		x+=lowbit(x);
	}
}
inline int get_sum(int x){
	int ret(0);
	while(x){
		ret+=c[x];
		x^=lowbit(x);
	}
	return ret;
}
struct node{
	int l2,r2,l3,r3,sum,size;
};
struct Tree{
	vector<int>ls,rs;
	vector<node>tree;
	void update(int i){
		tree[i].size=tree[i<<1].size+tree[(i<<1)|1].size;
		tree[i].l2=(tree[i<<1].l2+tree[(i<<1)|1].l2)%MOD;
		tree[i].r2=(tree[i<<1].r2+tree[(i<<1)|1].r2)%MOD;
		tree[i].l3=(tree[i<<1].l3+tree[(i<<1)|1].l3+1ll*tree[i<<1].l2*tree[(i<<1)|1].size)%MOD;
		tree[i].r3=(tree[i<<1].r3+tree[(i<<1)|1].r3+1ll*tree[i<<1].size*tree[(i<<1)|1].r2)%MOD;
		tree[i].sum=(tree[i<<1].sum+tree[(i<<1)|1].sum+1ll*tree[i<<1].l2*tree[(i<<1)|1].r3+1ll*tree[i<<1].l3*tree[(i<<1)|1].r2)%MOD;
	}
	void insert(int i,int l,int r,int pos,int d){
		if(l==r){
			tree[i].l2=ls[l]*d,tree[i].r2=rs[l]*d;
			tree[i].size=d;
			return;
		}
		int mid((l+r)>>1);
		if(pos<=mid)
			insert(i<<1,l,mid,pos,d);
		else
			insert((i<<1)|1,mid+1,r,pos,d);
		update(i);
	}
}root[MAXN+10];
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]),r[i]=a[i];
	sort(r+1,r+n+1);
	rcnt=unique(r+1,r+n+1)-r-1;
	for(i=1;i<=n;i++){
		a[i]=lower_bound(r+1,r+rcnt+1,a[i])-r;
		root[a[i]].ls.pb(get_sum(a[i]));
		update(a[i],1);
		pos[i]=root[a[i]].ls.size()-1;
	}
	memset(c,0,sizeof c);
	for(i=1;i<=rcnt;i++)
		root[i].tree.resize(root[i].ls.size()*4);
	for(i=n;i;i--){
		root[a[i]].rs.pb(get_sum(a[i]));
		update(a[i],1);
	}
	for(i=1;i<=rcnt;i++)
		reverse(all(root[i].rs));
	for(i=1;i<=n;i++)
		root[a[i]].insert(1,0,root[a[i]].ls.size()-1,pos[i],1);
	for(i=1;i<=rcnt;i++)
		ans=(ans+root[i].tree[1].sum)%MOD;
}
void solve(){
	int p,l;
	Read(Q);
	while(Q--){
		Read(p),Read(l);
		ans=(ans+MOD-root[a[l]].tree[1].sum)%MOD;
		root[a[l]].insert(1,0,root[a[l]].ls.size()-1,pos[l],p-1);
		ans=(ans+root[a[l]].tree[1].sum)%MOD;
		printf("%d\n",ans);
	}
}
int main()
{
	read();
	solve();
}