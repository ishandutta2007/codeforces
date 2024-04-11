#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000020;
int n,i,j,a[N],mid,opt;
long long k,s;
void init(){
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
}
void work(){
	mid=n+1>>1;
	for(i=1;i<=mid;i++)
		s+=a[mid]-a[i];
	for(;i<=n;i++)
		s+=a[i]-a[mid];
	if(s<=k){
		printf("0");
		return;
	}
	i=1;j=n;
	opt=0;
	while(i+1<j){
		if(1ll*(a[i+1]-a[i])*i<=k){
			k-=1ll*(a[i+1]-a[i])*i;
			i++;
		}
		else{
			a[i]+=k/i;
			opt=1;
			break;
		}
		if(1ll*(a[j]-a[j-1])*(n-j+1)<=k){
			k-=1ll*(a[j]-a[j-1])*(n-j+1);
			j--;
		}
		else{
			a[j]-=k/(n-j+1);
			opt=1;
			break;
		}		
	}
	if(i+1==j&&opt==0)
		printf("%d",a[j]-a[i]-k/i);
	else
		printf("%d",a[j]-a[i]);
}
int main(){
	init();
	work();
	return 0;
}