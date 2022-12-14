#include<iostream>
using namespace std;
int a[111],n,k,cur,pr;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		cur=min(8,a[i]+pr);
		if (cur>=k)
		{
			cout<<i<<endl;
			return 0;
		}
		pr=pr+a[i]-cur;
		k-=cur;
	}
	cout<<-1<<endl;
	return 0;
}