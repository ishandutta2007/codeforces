#include<bits/stdc++.h>
using namespace std;
int n,a[111111],x,y,z;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=n-1;i>1;i--)
	{
		if (a[i-2]+a[i-1]>a[i]) 
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}