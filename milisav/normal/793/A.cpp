#include <bits\stdc++.h>
using namespace std;
int n;
int a[200000];
int k;
int m;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	m=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]%k!=a[i-1]%k)
		{
			printf("-1");
			return 0;
		}
		if(a[i]<m) m=a[i];
	}
	long long p,r=0;
	for(int i=0;i<n;i++)
	{
		p=(a[i]-m)/k;
		r=r+p;
	}
	cout<<r<<endl;
	return 0;
}