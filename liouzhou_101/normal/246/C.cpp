#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int a[110];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=n;i>=1;--i)
		for (int j=1;j<=i;++j)
		{
			cout<<n-i+1<<" "<<a[j];
			for (int p=i+1;p<=n;++p)
				cout<<" "<<a[p];
			cout<<endl;
			if (!--k) return 0;
		}
	return 0;
}