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
#define MAXN 200000
int d[MAXN+10],n,rt;
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
int dfs(int u,int fa){
	vector<int>c;
	for(node *p=adj[u];p;p=p->next){
		if(p->v==fa)
			continue;
		int t=dfs(p->v,u);
		if(t<0)
			return t;
		else
			c.push_back(t+1); 
	}
	if(u==rt){
		sort(c.begin(),c.end());
		c.erase(unique(c.begin(),c.end()),c.end());
		if(c.size()==2)
			return c.front()+c.back();
		else if(c.size()==1)
			return c.front();
		return -u;
	}
	if(c.empty())
		return 0;
	int mx=*max_element(c.begin(),c.end()),mi=*min_element(c.begin(),c.end());
	
	if(mx==mi)
		return mx;
	else
		return -u;
}
void read(){
	Read(n);
	int i,u,v;
	for(i=1;i<n;i++){
		Read(u),Read(v);
		addedge(u,v);
		addedge(v,u);
		d[u]++,d[v]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]>2)
			rt=i;
	if(!rt)
		printf("%d\n",(n-1)>>__builtin_ctz(n-1));
	else{
		int t=dfs(rt,0);
		if(t==-rt)
			puts("-1");
		else if(t>=0)
			printf("%d\n",t>>__builtin_ctz(t));
		else{
			rt=-t;
			t=dfs(-t,0);
			if(t<0)
				puts("-1");
			else
				printf("%d\n",t>>__builtin_ctz(t));
		}
	}
}
int main()
{
	
	read();
}