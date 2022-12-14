#include<iostream>
using namespace std;
int a[2222],n,g,cnt,mn,len;
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
bool f;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	g=a[1];
	if (g==1) cnt++;
	for (int i=2;i<=n;i++)
	{
		g=gcd(g,a[i]);
		if (a[i]==1) cnt++;
	}
	if (g>1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		if (gcd(a[i],a[i+1])==1) f=1;
	}
	if (n==1 && a[1]==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if (f) cout<<n-cnt<<endl;
	else 
	{
		mn=1e9;
		for (int i=1;i<=n;i++)
		{
			g=a[i];len=1;
			for (int j=i+1;j<=n;j++)
			{
				g=gcd(g,a[j]);len++;
				if (g==1)
				{
					mn=min(mn,len);
					break;
				}
			}
		}
		cout<<n+mn-2<<endl;
	}
	return 0;
}