#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,i,a[N],ans[N],b[N],cnt;
bool ok1(){
	for(i=1;i<n;i++)
		if(a[i]!=a[i+1])
			return 0;
	return 1;
}
bool ok2(){
	for(i=1;i<n-1;i++)
		if(a[i]+a[i+2]!=a[i+1]*2)
			return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	ans[0]=1<<30;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(n==1){
		printf("-1");
		return 0;
	}
	if(n==2){
		if(a[1]==a[2]){
			printf("1\n%d",a[1]);
			return 0;
		}
		if(a[2]-a[1]&1){
			printf("2\n%d %d",a[1]*2-a[2],a[2]*2-a[1]);
			return 0;
		}
		printf("3\n%d %d %d",a[1]*2-a[2],a[1]+a[2]>>1,a[2]*2-a[1]);
		return 0;
	}
	if(ok1()){
		printf("1\n%d",a[1]);
		return 0;
	}
	if(ok2()){
		printf("2\n%d %d",a[1]*2-a[2],a[n]*2-a[n-1]);
		return 0;
	}
	for(i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	for(i=1;i<n-2;i++)
		if(b[i]!=b[i+1]){
			printf("0");
			return 0;
		}
	if(b[n-2]*2!=b[n-1]){
		printf("0");
		return 0;
	}
	for(i=1;i<n;i++)
		if(a[i+1]-a[i]==b[n-1]){
			printf("1\n%d",a[i]+a[i+1]>>1);
			return 0;
		}
		
}