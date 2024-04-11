#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a[MAXN];
ll f[MAXN],sum[MAXN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll mx;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(i==1) mx=a[i];
			f[i]=min(f[i-1],sum[i]=sum[i-1]+a[i]);
			if(i<n) mx=max(mx,sum[i]-f[i-1]);
		}
		for(int i=1; i<n; i++)
			mx=max(mx,sum[n]-sum[i]);
		if(sum[n]>mx) puts("YES");
		else puts("NO");
	}
	return 0;
}