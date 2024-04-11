#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN];
int ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		ans=1;
		for(int i=1; i<=n; i++)
			if(a[i]<=i) ans=i+1;
		printf("%d\n",ans);
	}
	return 0;
}