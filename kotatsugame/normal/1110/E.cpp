#include<iostream>
#include<algorithm>
using namespace std;
int n,c[1<<17],t[1<<17],a[1<<17],b[1<<17];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(i)a[i-1]=c[i]-c[i-1];
	}
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
		if(i)b[i-1]=t[i]-t[i-1];
	}
	sort(a,a+n-1);
	sort(b,b+n-1);
	bool flag=c[0]==t[0]&&c[n-1]==t[n-1];
	for(int i=0;i<n-1;i++)flag&=a[i]==b[i];
	cout<<(flag?"Yes":"No")<<endl;
}