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
		int i,j,k;
		for(i=0;i<sz;i++)
			for(j=0;j<sz;j++)
				if(a[i][j])
					for(k=0;k<sz;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%MOD;
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
#define MAXN 1000
int n,pos[MAXN+10],col[MAXN+10],f[2][MAXN+10],c[10];
uint mx;
string b[MAXN+10],a;
void read(){
	cin>>a;
	reverse(all(a));
	int i;
	Read(n);
	for(i=1;i<=n;i++){
		cin>>b[i];
		reverse(all(b[i]));
		while(b[i].size()<a.size())
			b[i]+='0';
		mx=max(mx,(uint)b[i].length());
	}
	for(i=0;i<10;i++)
		Read(c[i]);
}
void solve(){
	int i,j,l,r,jw,sum,now=0,k;
	for(i=1;i<=n;i++)
		pos[i]=i;
	memset(f[0],0xff,sizeof f[0]);
	**f=0;
	for(i=0;i<a.size();i++){
		now^=1;
		memset(f[now],0xff,sizeof f[now]);
		for(j=1;j<=n;j++)
			col[j]=b[j][i]-'0';
		if(i>=a.size())
			l=r=0;
		if(a[i]=='?'){
			l=(i==a.size()-1)?1:0;
			r=9;
		}
		else
			l=r=a[i]-'0';
		for(j=l;j<=r;j++){
			jw=0,sum=0;
			for(k=1;k<=n;k++) {
				sum+=c[(col[k]+j)%10];
				jw+=(col[k]+j)/10;
			}
			for(k=0;k<=n;k++){
				if(k){
					sum-=c[(col[pos[k]]+j)%10];
					jw-=(col[pos[k]]+j)/10;
					sum+=c[(col[pos[k]]+j+1)%10];
					jw+=(col[pos[k]]+j+1)/10;
				}
				if(~f[now^1][k])
					f[now][jw]=max(f[now][jw],f[now^1][k]+sum);
			}
		}
		stable_sort(pos+1,pos+1+n,[](int x,int y){return col[x]>col[y];});
	}
	for(i=a.size();i<=mx;i++){
		jw=sum=0;
		for(j=1;j<=n;j++)
			if(i>=b[j].size())
				col[j]=-1;
			else{
				col[j]=b[j][i]-'0';
				sum+=c[col[j]];
			}
		now^=1;
		memset(f[now],0xff,sizeof f[now]);
		for(j=0;j<=n;j++){
			if(j){
				if(~col[pos[j]])
					sum-=c[col[pos[j]]];
				sum+=c[(max(col[pos[j]],0)+1)%10];
				jw+=col[pos[j]]==9;
			}
			if(~f[now^1][j])
				f[now][jw]=max(f[now][jw],f[now^1][j]+sum);
		}
		stable_sort(pos+1,pos+1+n,[](int x,int y){return col[x]>col[y];});
	}
	cout<<f[now][0]<<endl;
}
int main()
{
	read();
	solve();
}