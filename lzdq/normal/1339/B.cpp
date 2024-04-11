#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n;
int a[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		int l=n+1>>1,r=n+1>>1;
		printf("%d ",a[l]);
		for(int i=1; i<n; i++){
			if(l-1>=n-r) printf("%d ",a[--l]);
			else printf("%d ",a[++r]);
		}
		puts("");
	}
	return 0;
}