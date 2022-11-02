#include <stdio.h>
#include <algorithm>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	char s[101];
	int a[50],i,n;
	scanf("%s",s);
	n=strlen(s)/2+1;
	for(i=0;i<n;i++){
		a[i]=s[i*2]-'0';
	}
	std::sort(a,a+n);
	for(i=0;i<n-1;i++){
		printf("%d+",a[i]);
	}
	printf("%d",a[i]);
}