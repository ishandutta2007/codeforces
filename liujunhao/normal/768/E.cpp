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
int sg[100];
void prepare(){
	sg[1]=1;
sg[2]=1;
sg[3]=2;
sg[4]=2;
sg[5]=2;
sg[6]=3;
sg[7]=3;
sg[8]=3;
sg[9]=3;
sg[10]=4;
sg[11]=4;
sg[12]=4;
sg[13]=4;
sg[14]=4;
sg[15]=5;
sg[16]=5;
sg[17]=5;
sg[18]=5;
sg[19]=5;
sg[20]=5;
sg[21]=6;
sg[22]=6;
sg[23]=6;
sg[24]=6;
sg[25]=6;
sg[26]=6;
sg[27]=6;
sg[28]=7;
sg[29]=7;
sg[30]=7;
sg[31]=7;
sg[32]=7;
sg[33]=7;
sg[34]=7;
sg[35]=7;
sg[36]=8;
sg[37]=8;
sg[38]=8;
sg[39]=8;
sg[40]=8;
sg[41]=8;
sg[42]=8;
sg[43]=8;
sg[44]=8;
sg[45]=9;
sg[46]=9;
sg[47]=9;
sg[48]=9;
sg[49]=9;
sg[50]=9;
sg[51]=9;
sg[52]=9;
sg[53]=9;
sg[54]=9;
sg[55]=10;
sg[56]=10;
sg[57]=10;
sg[58]=10;
sg[59]=10;
sg[60]=10;
}
int n,ans;
int main()
{
	prepare();
	Read(n);
	int a;
	for(int i=1;i<=n;i++){
		Read(a);
		ans^=sg[a];
	}
	if(ans)
		puts("NO");
	else
		puts("YES");
}