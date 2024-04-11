#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll INF=1ll<<60;
int n;
struct node{
	int w,id;
}a[MAXN];
bool operator <(node a,node b){
	return a.w<b.w;
}
ll f[MAXN];
int pre[MAXN];
int k,ans[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i].w),a[i].id=i;
	sort(a+1,a+n+1);
	f[1]=f[2]=INF;
	for(int i=3; i<=n; i++){
		f[i]=f[i-3]-a[i-2].w;
		pre[i]=i-3;
		if(i>=4&&f[i-4]-a[i-3].w<f[i]) f[i]=f[i-4]-a[i-3].w,pre[i]=i-4;
		if(i>=5&&f[i-5]-a[i-4].w<f[i]) f[i]=f[i-5]-a[i-4].w,pre[i]=i-5;
		f[i]+=a[i].w;
	}
	int u=n;
	while(u){
		int v=pre[u];
		k++;
		for(int i=v+1; i<=u; i++)
			ans[a[i].id]=k;
		u=v;
	}
	printf("%lld %d\n",f[n],k);
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}