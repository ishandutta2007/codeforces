#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100020;
typedef long long ll;
int n,m,i,a[N],b[N];
ll ans;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;i++)
		scanf("%d",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
}
void work(){
	if(a[n]>b[1]){
		printf("-1");
		return;
	}
	if(a[n]==b[1]){
		for(i=1;i<n;i++)
			ans+=1ll*a[i]*m;
		for(i=1;i<=m;i++)
			ans+=b[i];
		printf("%lld",ans);
	}
	else{
		for(i=1;i+1<n;i++)
			ans+=1ll*a[i]*m;
		ans+=1ll*a[i]*(m-1);
		ans+=a[n];
		for(i=1;i<=m;i++)
			ans+=b[i];
		printf("%lld",ans);			
	}
}
int main(){
	init();
	work();
	return 0;
}