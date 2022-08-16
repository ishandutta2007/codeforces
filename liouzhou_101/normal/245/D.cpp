#include<cstdio>
#include<iostream>

using namespace std;

int n;
int a[110];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			int x;
			cin>>x;
			if (i==j) continue;
			a[i]|=x;
		}
	for (int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	return 0;
}