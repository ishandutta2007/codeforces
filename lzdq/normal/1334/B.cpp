#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
int n,x;
int a[MAXN];
ll ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&x);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		ll sum=0;
		ans=0;
		for(int i=n; i; i--){
			sum+=a[i];
			if(sum<x*(n-i+1ll)) break;
			ans=n-i+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}