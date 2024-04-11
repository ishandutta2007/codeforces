#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN];
int x[MAXN],y[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ll ans=0;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i),ans+=b[i];
		*x=*y=0;
		for(int i=1; i<=n; i++)
			if(a[i]) x[++*x]=b[i];
			else y[++*y]=b[i];
		sort(x+1,x+*x+1);
		reverse(x+1,x+*x+1);
		sort(y+1,y+*y+1);
		reverse(y+1,y+*y+1);
		int l=min(*x,*y);
		for(int i=1; i<=l; i++)
			ans+=x[i]+y[i];
		if(l*2==n) ans-=min(x[l],y[l]);
		printf("%lld\n",ans);
	}
	return 0;
}