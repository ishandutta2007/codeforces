#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[50];
int n,m;
ll getans(int m,int n)
{
	if (m==0)	return 0;
	if (m<(1LL<<(n-1)))	return min(a[n],getans(m,n-1));
	return a[n]+getans(m-(1LL<<(n-1)),n-1);
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=n-1;i>=1;i--)
		if (a[i]>a[i+1])	a[i]=a[i+1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]>a[i-1]*2)	a[i]=a[i-1]*2;
	}
	for (int i=n+1;i<=32;i++)
		a[i]=a[i-1]*2;
	cout<<getans(m,32)<<endl;
	return 0;
}