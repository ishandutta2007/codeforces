#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1111];
int main()
{
	int T,n,i;cin>>T;
	while (T--)
	{
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n]+a[n-1]<<endl;
	}
}