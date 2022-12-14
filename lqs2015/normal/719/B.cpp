#include<iostream>
using namespace std;
int n,ans,mx,my;
char a[111111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (i%2 && a[i]!='r') mx++;
		if (!(i%2) && a[i]!='b') my++;
	}
	ans=max(mx,my);
	mx=my=0;
	for (int i=1;i<=n;i++)
	{
		if (i%2 && a[i]!='b') mx++;
		if (!(i%2) && a[i]!='r') my++;
	}
	ans=min(ans,max(mx,my));
	cout<<ans<<endl;
	return 0;
}