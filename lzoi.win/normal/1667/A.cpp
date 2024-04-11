#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=5005;
const ll INF=1ll<<60;
int n,a[MAXN];
ll ans=INF;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		ll mi=0,tot=0;
		for(int j=i-1; j; j--){
			tot+=mi/a[j]+1;
			mi=a[j]*(mi/a[j]+1);
		}
		mi=0;
		for(int j=i+1; j<=n; j++){
			tot+=mi/a[j]+1;
			mi=a[j]*(mi/a[j]+1);
		}
		ans=min(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
}