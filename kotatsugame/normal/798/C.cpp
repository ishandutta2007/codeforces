#include<iostream>
using namespace std;
long a[1<<17];int n;
long gcd(long s,long t){return t==0?s:s<t?gcd(t,s):gcd(t,s%t);}
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	long b=gcd(a[0],a[1]);
	for(int i=2;i<n;i++)b=gcd(a[i],b);
	if(b>1)
	{
		cout<<"YES\n0"<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==1)
		{
			cnt+=2;
			if(i!=n-1&&a[i+1]%2==1)a[i+1]=0,cnt--;
		}
	}
	cout<<"YES"<<endl;
	cout<<cnt<<endl;
}