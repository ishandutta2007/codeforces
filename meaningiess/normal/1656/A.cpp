#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];
int main()
{
	int T;cin>>T;a[0]=1e9+1;
	while (T--)
	{
		int n,i,mn=0,mx=n+1;cin>>n;
		a[n+1]=0;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]>a[mx]) mx=i;
			if (a[i]<a[mn]) mn=i;
		}
		cout<<min(mn,mx)<<' '<<max(mn,mx)<<endl;
	}
}