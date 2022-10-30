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
int len,ans;
LL n,l,r;
void read(){
	Read(n),Read(l),Read(r);
	for(len=50;len;len--)
		if((1ll<<len)&n)
			break;
}
void dfs(LL now,LL x,LL y){
	if(x>r||y<l)
		return;
	if(x==y){
		ans+=now;
		return;
	}
	LL mid=(x+y)>>1;
	dfs(now>>1,x,mid-1);
	if(l<=mid&&mid<=r)
		ans+=now&1;
	dfs(now>>1,mid+1,y);
}
int main()
{
	read();
	dfs(n,1,(1ll<<(len+1))-1);
	printf("%d\n",ans);
}