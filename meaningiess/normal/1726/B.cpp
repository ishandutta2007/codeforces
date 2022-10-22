#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;cin>>n>>m;
		for (i=1;i<=n;i++) a[i]=1;
		m-=n;
		if (m<0) {puts("No");continue;}
		if (n&1)
		{
			a[n]+=m;
			puts("Yes");
			for (i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
		}
		else
		{
			if (m&1) puts("No");
			else
			{
				m/=2;
				a[n]+=m;
				a[n-1]+=m;
				puts("Yes");
				for (i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
			}
		}
	}
}