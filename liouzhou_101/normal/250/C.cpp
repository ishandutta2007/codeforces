#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=100010;

int n,k;
int a[MaxN],p[MaxN];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i)
	{
		if (a[i]==a[i-1]) continue;
		int j=i;
		p[a[i]]++;
		while (a[j+1]==a[i]) ++j;
		if (a[i-1]==a[j+1]) p[a[i]]++;
	}
	int t=1;
	for (int i=1;i<=k;++i)
		if (p[i]>p[t]) t=i;
	cout<<t<<endl;
	return 0;
}