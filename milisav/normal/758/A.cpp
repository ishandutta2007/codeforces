#include <iostream>
#include <cstdio>
using namespace std;
int n;
int m=0;
int r=0;
int a[1000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	m=a[0];
	for(int i=1;i<n;i++) if(a[i]>m) m=a[i];
	for(int i=0;i<n;i++) r+=m-a[i];
	printf("%d",r);
	return 0;
}