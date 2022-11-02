#include<bits/stdc++.h>
using namespace std;
int n,m;
long long  a[200005]; 
long long ans;
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	int T=read();
	while (T--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) a[i]=0;
		for (int i=1;i<=n;i++) 
		{
			int x=read();
			a[x]++;
		}
		ans=0;
		for (int i=1;i<=n;i++) 
		{
			ans=ans+a[i]*(a[i]-1)*(a[i]-2)/6ll;
		}
		for (int i=1;i<n;i++)
		{
			ans=ans+a[i]*(a[i]-1)*a[i+1]/2ll;
			ans=ans+a[i+1]*(a[i+1]-1)*a[i]/2ll;
		}
		for (int i=2;i<n;i++)
		{
			ans=ans+a[i]*(a[i-1])*a[i+1];
		}
		for (int i=1;i<n-1;i++)
		{
			ans=ans+a[i]*(a[i]-1)*a[i+2]/2ll;
			ans=ans+a[i+2]*(a[i+2]-1)*a[i]/2ll;
		}
		cout << ans << endl;
	}
	return 0;
}