#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
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
	inline point(pointtype x,pointtype y):x(x),y(y){
	}
	inline point operator-(const point &a)const{
		return point(x-a.x,y-a.y);
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
//template
#define MAXN 100000
int n,fa[MAXN+10],f[MAXN+10];
int r[MAXN+10],cnt;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void read(){
	int i;
	Read(n);
	for(i=1;i<=n;i++)
		Read(fa[i]);
	for(i=1;i<=n;i++)
		if(fa[fa[i]]!=fa[i]){
			puts("-1");
			return;
		}
	for(i=1;i<=n;i++)
		if(fa[i]==i)
			r[i]=++cnt;
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		printf("%d ",r[fa[i]]);
	puts("");
	for(i=1;i<=n;i++)
		if(fa[i]==i)
			printf("%d ",i);
}
int main()
{
	
	read();
}