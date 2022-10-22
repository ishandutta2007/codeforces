#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5,MAXP=1e7,MAXM=2e7;
int n;
ll s1,c1,s2,c2,pri[MAXN];
int a[MAXN][2],p1[MAXN],p2[MAXN],q[MAXN];
bool cmpmod;
inline bool cmp(int x,int y){
	if(pri[x]!=pri[y]) return pri[x]<pri[y];
	if(cmpmod) return a[x][0]+a[x][1]<a[y][0]+a[y][1];
	return a[x][0]+a[x][1]>a[y][0]+a[y][1];
}
int f[MAXN],mx[MAXN];
inline int query(int x){
	int res=0;
	for(int i=x; i<=n; i+=i&-i)
		res=max(res,mx[i]);
	return res;
}
inline void add(int x,int y){
	for(int i=x; i; i&=i-1)
		mx[i]=max(mx[i],y);
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	scanf("%lld/%lld %lld/%lld",&s1,&c1,&s2,&c2);
	for(int i=1; i<=n; i++)
		scanf("%d%d",a[i],a[i]+1);
	n++;
	for(int i=1; i<=n; i++)
		pri[i]=c1*a[i][1]-s1*a[i][0],p1[i]=i;
	sort(p1+1,p1+n+1,cmp);
	for(int i=1; i<=n; i++)
		pri[i]=c2*a[i][1]-s2*a[i][0],p2[i]=i;
	cmpmod=1;
	sort(p2+1,p2+n+1,cmp);
	for(int i=1; i<=n; i++)
		q[p1[i]]=i;
	for(int i=1; i<=n; i++){
		int u=p2[i];
		f[u]=query(q[u])+1;
		add(q[u],f[u]);
	}
	printf("%d\n",f[n]-1);
	return 0;
}