#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5,INF=0x3fffffff;
int n,a[MAXN];
ll b[MAXN],c[MAXN];
int m;
int f[MAXN];
int s1[MAXN],s2[MAXN];
inline void add(int x,int y){
	for(int i=x; i<=m; i+=i&-i)
		s1[i]=max(s1[i],y);
}
inline int query(int x){
	int res=-INF;
	for(int i=x; i; i&=i-1)
		res=max(res,s1[i]);
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),c[i]=b[i]=b[i-1]+a[i];
		c[n+1]=0;
		sort(c+1,c+n+2);
		m=unique(c+1,c+n+2)-c-1;
		for(int i=1; i<=m; i++)
			s1[i]=s2[i]=-INF;
		add(lower_bound(c+1,c+m+1,0)-c,0);
		s2[lower_bound(c+1,c+m+1,0)-c]=0;
		for(int i=1; i<=n; i++){
			int w=lower_bound(c+1,c+m+1,b[i])-c;
			f[i]=max(f[i-1],query(w-1)+i*2);
			f[i]=max(f[i],s2[w]+i);
			add(w,f[i]-i*2);
			s2[w]=max(s2[w],f[i]-i);
		}
		printf("%d\n",f[n]-n);
	}
	return 0;
}