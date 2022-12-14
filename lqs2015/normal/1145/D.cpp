#include<bits/stdc++.h>
using namespace std;
int n,a[55],b[55],cnt,mn;
int main()
{
	cin>>n;mn=1e9;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		mn=min(mn,a[i]);
	}
//	sort(a+1,a+n+1);
	cout<<(2+(a[3]^mn))<<endl;
	return 0;
}