#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		n -= i;
	--i;
	printf("%d\n",i);
	for(j=1; j<i; j++)
		printf("%d ",j);
	printf("%d\n",i+n);
	return 0;
}