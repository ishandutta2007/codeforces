#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,a[N],i;
long long s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s+=a[i];
	if(s%2){
		printf("NO");
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[n]>s/2)
		printf("NO");
	else
		printf("YES");
}