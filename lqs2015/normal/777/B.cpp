#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1111],b[1111],used[1111],ans1,ans2;
char c;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c;
		a[i]=c-'0';
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c;
		b[i]=c-'0';
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++)
	{
		bool f=0;
		for (int j=1;j<=n;j++)
		{
			if (b[j]>=a[i] && !used[j])
			{
				f=1;
				used[j]=1;
				break;
			}
		}
		if (!f) ans1++;
	}
	for (int i=1;i<=n;i++) used[i]=0;
	for (int i=1;i<=n;i++)
	{
		bool f=0;
		for (int j=1;j<=n;j++)
		{
			if (b[j]>a[i] && !used[j])
			{
				f=1;
				used[j]=1;
				break;
			}
		}
		if (f) ans2++;
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}