#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,m;
int a[MAXN];
int ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int k=0,mi=-2e9;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			while(a[i]+(1ll<<k)-1<mi) k++;
			mi=max(mi,a[i]);
		}
		printf("%d\n",k);
	}
	return 0;
}