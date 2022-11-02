#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,i,a[N],b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",b+i);		
	if(a[1]!=b[1]||a[n]!=b[n]){
		printf("No");
		return 0;
	}
	for(i=1;i<n;i++)
		a[i]=a[i+1]-a[i],
		b[i]=b[i+1]-b[i];
	sort(a+1,a+n);
	sort(b+1,b+n);
	for(i=1;i<n;i++)
		if(a[i]!=b[i]){
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}