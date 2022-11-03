#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 200005
#define LL long long

int n,sum,ans[N];

struct peo{
	int w,h,id;
	void read(){scanf("%d%d",&w,&h);}
}a[N]; 

inline bool cmp(const peo &a,const peo &b){return a.h>b.h;}

int main(){
	scanf("%d",&n);
	rep(i,1,n) a[i].read(),a[i].id=i,sum+=a[i].w;
	sort(a+1,a+1+n,cmp);
	ans[a[1].id]=a[2].h*(sum-a[1].w);
	rep(i,2,n) ans[a[i].id]=a[1].h*(sum-a[i].w);
	rep(i,1,n) printf("%d ",ans[i]);
}