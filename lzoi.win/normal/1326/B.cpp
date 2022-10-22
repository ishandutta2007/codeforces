#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n;
int a[MAXN],b[MAXN];
int mx;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",b+i);
	for(int i=1; i<=n; i++){
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}