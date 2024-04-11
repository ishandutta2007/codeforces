#include<iostream>
using namespace std;
int n,a[111111],l,r,mx;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	l=r=1;
	for (;r<=n;r++)
	{
		while (a[r]>a[r-1] && r<=n) r++;
		mx=max(mx,r-l);
		l=r;
	}
	cout<<mx<<endl;
	return 0;
}