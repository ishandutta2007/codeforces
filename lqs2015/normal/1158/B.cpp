#include<bits/stdc++.h>
using namespace std;
int n,k,a;
int main()
{
	cin>>n>>k;
	a=(n-k)/2;
	for (int i=1;i<=n;i++)
	{
		if (i%(a+1)==0) cout<<'1';
		else cout<<'0';
	}
	cout<<endl;
	return 0;
}