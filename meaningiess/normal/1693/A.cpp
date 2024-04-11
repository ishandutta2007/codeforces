#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		while (n && a[n]==0) n--;
		ll s=0;
		for (i=1;i<=n;i++)
		{
			s+=a[i];
			if (s<=0) break;
		}
		if (s!=0 || i<n) puts("No");
		else puts("Yes");
	}
}