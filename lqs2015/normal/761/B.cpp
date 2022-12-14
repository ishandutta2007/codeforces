#include<iostream>
#include<algorithm>
using namespace std;
int a[111],b[111],n,l,p[111];
bool f;
int main()
{
	cin>>n>>l;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=0;i<l;i++)
	{
		for (int j=1;j<=n;j++)
		{
			p[j]=a[j]-i;
			if (p[j]<0) p[j]+=l;
		}
		sort(p+1,p+n+1);
		f=0;
		for (int j=1;j<=n;j++)
		{
			if (p[j]!=b[j]) f=1;
		}
		if (!f)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}