#include<cstdio>
#include<algorithm>
using namespace std;

int a[600001];
long long b[600001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]-i+n]+=a[i];
	}
	long long ans=-1;
	for(int i=0;i<=600000;i++)
		ans=max(ans,b[i]);
	printf("%lld\n",ans);
}