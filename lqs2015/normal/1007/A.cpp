#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[111111],r,cnt;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	r=1;
	for (int i=1;i<=n;i++)
	{
		while(r<=n && a[r]<=a[i]) r++;
		if (r>n) break;
		cnt++;
		r++;
	}
	printf("%d\n",cnt);
	return 0;
 }