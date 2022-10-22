#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,ans=0;cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]!=0 && a[i-1]==0) ans++;
		}
		cout<<min(ans,2)<<endl;
	}
}