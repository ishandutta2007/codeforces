#include<stdio.h>
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
#include<unordered_map>
#include<unordered_set>
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
	inline void clear(){
		memset(a,0,sizeof a);
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
	inline cpx(double r,double i=0):r(r),i(i){
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
namespace mypq{
	template<class T,class Container=std::vector<T>,class cmp=std::less<typename Container::value_type> >
	struct priority_queue{
		std::priority_queue<T,Container,cmp>ins,del;
		inline void push(T a){
			ins.push(a);
		}
		inline void erase(T a){
			del.push(a);
		}
		inline void pop(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			ins.pop();
		}
		inline T top(){
			while(!del.empty()&&ins.top()==del.top())
				ins.pop(),del.pop();
			return ins.top();
		}
		inline T second_top(){
			T tmp=top(),ret;
			pop();
			ret=top();
			push(tmp);
			return ret;
		}
		inline void clear(){
			while(!ins.empty())
				ins.pop();
			while(!del.empty())
				del.pop();
		}
		inline int size(){
			return ins.size()-del.size();
		}
		inline bool empty(){
			return !size();
		}
	};
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y){
    if(!b){
        d=a;
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,d,y,x);
    y-=a/b*x;
}
//template
#define MAXN 100000
int n,a[MAXN*2+10],le[20][MAXN*2+10],ri[20][MAXN*2+10],treel[20][MAXN*8+10],treer[20][MAXN*8+10],Log;
void buildmi(int *tree,int i,int l,int r,int *a){
	if(l==r){
		tree[i]=a[l];
		return;
	}
	int mid((l+r)>>1);
	buildmi(tree,i<<1,l,mid,a);
	buildmi(tree,(i<<1)|1,mid+1,r,a);
	tree[i]=min(tree[i<<1],tree[(i<<1)|1]);
}
void buildmx(int *tree,int i,int l,int r,int *a){
	if(l==r){
		tree[i]=a[l];
		return;
	}
	int mid((l+r)>>1);
	buildmx(tree,i<<1,l,mid,a);
	buildmx(tree,(i<<1)|1,mid+1,r,a);
	tree[i]=max(tree[i<<1],tree[(i<<1)|1]);
}
inline int Get_mi(int *tree,int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i];
	if(ll>r||rr<l)
		return 1e9;
	int mid((l+r)>>1);
	return min(Get_mi(tree,i<<1,l,mid,ll,rr),Get_mi(tree,(i<<1)|1,mid+1,r,ll,rr));
}
inline int Get_mx(int *tree,int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i];
	if(ll>r||rr<l)
		return 0;
	int mid((l+r)>>1);
	return max(Get_mx(tree,i<<1,l,mid,ll,rr),Get_mx(tree,(i<<1)|1,mid+1,r,ll,rr));
}
int main()
{
	Read(n);
	if(n==1){
		puts("0");
		return 0;
	}
	int i,j;
	for(Log=1;(1<<Log)<=n;Log++);
	for(i=1;i<=n;i++)
		Read(a[i]);
	memcpy(a+n+1,a+1,n*sizeof(int));
	n<<=1;
	for(i=1;i<=n;i++){
		ri[0][i]=min(i+a[i],n);
		le[0][i]=max(1,i-a[i]);
	}
	buildmx(treer[0],1,1,n,ri[0]);
	buildmi(treel[0],1,1,n,le[0]);
	for(i=1;i<=Log;i++){
		for(j=1;j<=n;j++){
			ri[i][j]=Get_mx(treer[i-1],1,1,n,le[i-1][j],ri[i-1][j]);
			le[i][j]=Get_mi(treel[i-1],1,1,n,le[i-1][j],ri[i-1][j]);
		}
		buildmx(treer[i],1,1,n,ri[i]);
		buildmi(treel[i],1,1,n,le[i]);
	}
	int tn=n>>1;
	for(i=1;i<=tn;i++){
		int l1=i,r1=i,l2=i+tn,r2=i+tn,ans=0;
		int tl1,tr1,tl2,tr2;
		for(j=Log;j>=0;j--){
			ans<<=1;
			tl1=Get_mi(treel[j],1,1,n,l1,r1);
			tr1=Get_mx(treer[j],1,1,n,l1,r1);
			tl2=Get_mi(treel[j],1,1,n,l2,r2);
			tr2=Get_mx(treer[j],1,1,n,l2,r2);
			if(tr1-tl1+1<tn&&tr2-tl2+1<tn){
				ans++;
				l1=tl1;
				r1=tr1;
				l2=tl2;
				r2=tr2;
			}
		}
		printf("%d ",ans+1);
	}
}