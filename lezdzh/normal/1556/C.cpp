#include<cstdio>
#include<algorithm>
using namespace std;

int a[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i+=2){
		long long o=0,mn=a[i];
		for(int j=i+1;j<=n;j+=2){
			ans+=max(0ll,min(mn,o+a[j-1]-1)-max(0ll,o+a[j-1]-a[j])+1);
			o+=a[j-1]-a[j];
			mn=min(o,mn);
		}
	}
	printf("%lld\n",ans);
}