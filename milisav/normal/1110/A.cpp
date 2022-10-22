#include<bits/stdc++.h>
using namespace std;
int main()
{
	int b,k;
	scanf("%d %d",&b,&k);
	int a,s=0;
	for(int i=0;i<k;i++) {
		scanf("%d",&a);
		if(b%2==0) s=a;
		else s+=a;
	}
	if(s%2==0) printf("even");
	else printf("odd");
	return 0;
}