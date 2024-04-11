#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int b[1000000];
int s=0;
int r=1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n && r<n;i++) {
		while(r<n && a[r]==a[i]) r++;
		if(r<n && a[r]>a[i]) {
			s++;
			r++;
		}
	}
	printf("%d",s);
	return 0;
}