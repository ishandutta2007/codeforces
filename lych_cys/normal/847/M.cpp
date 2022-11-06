#include<bits/stdc++.h>
using namespace std;

int n,a[100009];
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	for (i=2; i<n; i++) if (a[i+1]-a[i]!=a[2]-a[1]) break;
	printf("%d\n",(i<n)?a[n]:a[n]+a[n]-a[n-1]);
	return 0;
}