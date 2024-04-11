#include<stdio.h>
int n,a[111];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	bool flag = true;
	for(int i=1; i<n; i++)
		if(a[i] - a[i-1] != a[1] - a[0])
			flag = false;
	printf("%d\n",flag ? a[n-1] + (a[1] - a[0]) : a[n-1]);
	return 0;
}