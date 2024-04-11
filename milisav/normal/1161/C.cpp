#include<bits/stdc++.h>
using namespace std;
int n;
int a[300];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int k=n/2;
	if(a[k]==a[0]) printf("Bob");
	else printf("Alice");
	return 0;
}