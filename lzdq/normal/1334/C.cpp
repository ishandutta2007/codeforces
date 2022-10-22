#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
typedef long long ll;
int n;
ll a[MAXN],b[MAXN];
int ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%lld%lld",a+i,b+i);
		ll sum=0,mi=a[1]-max(a[1]-b[n],0ll);
		for(int i=2; i<=n; i++)
			mi=min(mi,a[i]-max(a[i]-b[i-1],0ll));
		for(int i=1; i<=n; i++){
			if(i==1) a[i]-=b[n];
			else a[i]-=b[i-1];
			if(a[i]<0) a[i]=0;
			sum+=a[i];
		}
		printf("%lld\n",sum+mi);
	}
	return 0;
}