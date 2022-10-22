#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,INF=0x3fffffff;
int n,a[MAXN],b[MAXN];
int x[MAXN];
int mi[MAXN],mx[MAXN];
char ans[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),x[i]=a[i];
		mx[0]=0;
		mi[n+1]=INF;
		mx[n+1]=0;
		for(int i=1; i<=n; i++)
			scanf("%d",b+i),mi[i]=INF,mx[i]=0;
		sort(x+1,x+n+1);
		for(int i=1; i<=n; i++){
			int w=lower_bound(x+1,x+n+1,a[i])-x;
			mx[w]=max(mx[w],b[i]);
			mi[w]=min(mi[w],b[i]);
		}
		for(int i=1; i<=n; i++)
			mx[i]=max(mx[i],mx[i-1]);
		for(int i=n; i; i--)
			mi[i]=min(mi[i],mi[i+1]);
		int w=0;
		for(int i=1; i<n; i++)
			if(mx[i]<mi[i+1]) w=i;
		for(int i=1; i<=n; i++)
			ans[i]='1'-(a[i]<=x[w]);
		ans[n+1]=0;
		puts(ans+1);
	}
	return 0;
}