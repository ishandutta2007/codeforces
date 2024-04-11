#include<iostream>
using namespace std;
int a[222],b[222],n,k;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=k;i++) cin>>b[i];
	if (k>1) cout<<"Yes"<<endl;
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0) a[i]=b[1];
		}
		bool f=0;
		for (int i=2;i<=n;i++)
		{
			if (a[i]<a[i-1]) f=1;
		}
		if (!f) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}