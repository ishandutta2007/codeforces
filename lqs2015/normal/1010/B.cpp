#include<bits\stdc++.h>
using namespace std;
int n,m,k,l,r,mid,cur;
bool f[55];
int main()
{
	fflush(stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cout<<i<<endl;
		cin>>k;
		if (!k) return 0;
		if (k==1) f[i]=1;
	}
	l=n+1;r=m;
	while(l<=r)
	{
		cur=cur%n+1;
		mid=(l+r)/2;
		cout<<mid<<endl;
		cin>>k;
		if (!k) return 0;
		if (k==1)
		{
			if (f[cur]) l=mid+1;
			else r=mid-1;
		}
		else
		{
			if (f[cur]) r=mid-1;
			else l=mid+1;
		}
	}
	cout<<r<<endl;
	cin>>k;
	return 0;
}