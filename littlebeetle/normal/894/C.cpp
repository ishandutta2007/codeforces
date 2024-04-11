#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=100002;
int n,i,j,a[N],x;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	x=a[1];
	for(i=2;i<=n;i++)
		x=gcd(x,a[i]);
	if(x!=a[1])
		printf("-1");
	else{
		printf("%d\n",2*n);
		for(i=1;i<=n;i++)
			printf("%d %d ",a[i],a[1]);
		}
}