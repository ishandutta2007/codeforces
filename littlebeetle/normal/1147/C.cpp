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
	printf("%s",a[1]==a[n/2+1]?"Bob":"Alice");
}