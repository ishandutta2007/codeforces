#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=100002;
typedef long long ll;
int n,i,a[N],k;
ll sum;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
}
void work(){
	if(n>1&&a[2]==0){
		printf("cslnb");
		return;
	}
	for(i=2;i<n;i++)
		if(a[i-1]==a[i]-1&&a[i]==a[i+1]){
			printf("cslnb");
			return;
		}
	for(i=1;i<n;i++)
		if(a[i]==a[i+1])
			k++;
	if(k>=2){
		printf("cslnb");
		return;
	}
	for(i=1;i<=n;i++)
		sum+=a[i]-i+1;
	if(sum%2==0)
		printf("cslnb");
	else
		printf("sjfnb");
}
int main(){
	init();
	work();
}