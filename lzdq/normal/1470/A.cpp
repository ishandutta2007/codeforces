#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int n,m,a[MAXN],c[MAXN];
ll ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=m; i++)
			scanf("%d",c+i);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		ans=0;
		for(int i=1,j=1; i<=n; i++){
			if(j<a[i]) ans+=c[j],j++;
			else ans+=c[a[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}