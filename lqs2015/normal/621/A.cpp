#include<iostream>
using namespace std;
long long n,a[1111111],s,mn;
int main()
{
	cin>>n;
	mn=9999999999999;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		if (mn>a[i] && a[i]%2==1) mn=a[i];
	}
	if (s%2==0) cout<<s<<endl;
	else if (mn<999999999999) cout<<s-mn<<endl;
	else cout<<"0"<<endl;
	return 0;
}