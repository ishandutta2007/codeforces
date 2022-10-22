#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[10000];
int main()
{
	scanf("%d %d",&n,&d);
	int s=2;
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	for(int i=0;i<n-1;i++) {
		if(x[i+1]-x[i]==2*d) s=s+1;
		if(x[i+1]-x[i]>2*d) s=s+2;
	}
	printf("%d",s);
	return 0;
}