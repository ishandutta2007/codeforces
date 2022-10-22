#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[2000];
int b[2000];
int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	s--;
	if(a[0]==0) {
		printf("NO");
		return 0;
	}
	if(a[s]==1) {
		printf("YES");
		return 0;
	}
	if(b[s]==0) {
		printf("NO");
		return 0;
	}
	for(int i=s+1;i<n;i++) {
		if(a[i]==1 && b[i]==1) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}