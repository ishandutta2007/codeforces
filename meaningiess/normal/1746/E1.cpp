#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010],b[100010];
int main()
{
	int n,i;cin>>n;string s;
	for (i=1;i<=n;i++) a[i]=i;
	while (n>2)
	{
		int tp=n/3,l=tp,r=l+(n-tp)/2;
		cout<<"? "<<l<<' ';
		for (i=1;i<=l;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
		cin>>s;
		if (s[1]=='O')
		{
			cout<<"? "<<l<<' ';
			for (i=1;i<=l;i++)
			{
				cout<<a[i]<<' ';
			}
			cout<<endl;
			cin>>s;
			if (s[1]=='O')
			{
				for (i=1;i<=n-l;i++) a[i]=a[i+l];
				n-=l;continue;
			}
		}
		cout<<"? "<<r-l<<' ';
		for (i=l+1;i<=r;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
		cin>>s;
		if (s[1]=='O')
		{
			for (i=l+1;i<=n-r+l;i++) a[i]=a[i+r-l];
			n-=r-l;
		}
		else
		{
			n=r;
		}
	}
	cout<<"! "<<a[1]<<endl;
	cin>>s;
	if (s[1]=='(') cout<<"! "<<a[2]<<endl;
}