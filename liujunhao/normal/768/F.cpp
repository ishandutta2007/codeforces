#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
#define push_back pb
#define all(a) a.begin(),a.end()
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
#define MOD 1000000007
int fac[MAXN+10],inv[MAXN+10],p,q,f,w,h;
void prepare(){
	*fac=*inv=fac[1]=inv[1]=1;
	for(int i=2;i<=MAXN;i++){
		fac[i]=1ll*fac[i-1]*i%MOD;
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	}
	for(int i=2;i<=MAXN;i++)
		inv[i]=1ll*inv[i]*inv[i-1]%MOD;
}
void read(){
	Read(f),Read(w),Read(h);
}
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int quick_pow(int a,int b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		b>>=1;
		a=1ll*a*a%MOD;	
	}
	return ret;
}
void solve(){
	if(!w){
		puts("1");
		return;
	}
	if(w<=h){
		puts("0");
		return;
	}
	if(!f){
		puts("1");
		return;
	}
	int i;
	for(i=2;i<=w+f;i++){
		int tf=(i+1)>>1,tw=i>>1;
		LL noww=w-1ll*tw*h;
		if(f>=tf&&noww>=tw)
			p=(p+1ll*C(f-1,tf-1)*C(noww-1,tw-1))%MOD;
		if(f>=tf&&w>=tw)
			q=(q+1ll*C(f-1,tf-1)*C(w-1,tw-1))%MOD;
		tw=(i+1)>>1,tf=i>>1;
		noww=w-tw*h;
		if(f>=tf&&noww>=tw)
			p=(p+1ll*C(f-1,tf-1)*C(noww-1,tw-1))%MOD;
		if(f>=tf&&w>=tw)
			q=(q+1ll*C(f-1,tf-1)*C(w-1,tw-1))%MOD;
	}
	printf("%I64d\n",1ll*p*quick_pow(q,MOD-2)%MOD);
}
int main()
{
	prepare();
	read();
	
	solve();
}