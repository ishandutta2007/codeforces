#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int k;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	k=0;
	int s=0;
	for(int i=0;i<n;i++) {
		k=max(k,a[i]);
		s+=a[i];
	}
	if(k*n>2*s) printf("%d",k);
	else {
		int k1=(2*s-k*n)/n+1;
		while((k+k1-1)*n>2*s) k1--;
		while((k+k1)*n<=2*s) k1++;
		printf("%d",k+k1);
	}
	return 0;
}