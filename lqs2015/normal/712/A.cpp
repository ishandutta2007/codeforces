#include<iostream>
using namespace std;
int n,a[111111],b[111111],f;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	b[n]=a[n];f=a[n];
	for (int i=n-1;i>=1;i--) 
	{
		b[i]=a[i]+f;
		f=f*-1+b[i];
	}
	for (int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}