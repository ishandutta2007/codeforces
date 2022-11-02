#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int a[N],t,n,i,b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d",&t);
		a[i+1]=a[i]+t;
	}
	t=n;
	for(i=1;i<=n;i++)
		if(a[i]<t)
			t=a[i];
	t=1-t;
	for(i=1;i<=n;i++)
		a[i]+=t,b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
		if(b[i]!=i){
			printf("-1");
			return 0;
		}
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}