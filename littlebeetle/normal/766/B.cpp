#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,i,a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i+2<=n;i++)
		if(a[i]+a[i+1]>a[i+2]){
			printf("YES");
			return 0;
		}
	printf("NO");
}