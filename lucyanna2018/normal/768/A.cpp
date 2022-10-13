#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[1111111];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int res=0;
	for(int i=0; i<n; i++)
		if(a[i]!=a[0] && a[i]!=a[n-1])
			res++;
	printf("%d\n",res);
	return 0;
}