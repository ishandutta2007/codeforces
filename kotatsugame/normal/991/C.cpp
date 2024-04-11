#include<iostream>
using namespace std;
long long n,f=1,l;
main()
{
	cin>>n;
	l=n+1;
	for(int i=0;i<100;i++)
	{
		long long m=(f+l)/2;
		long long cnt=0,now=n;
		while(now>0)
		{
			if(now<m)cnt+=now,now=0;
			else cnt+=m,now-=m;
			now-=now/10;
		}
		if(cnt*2<n)f=m;
		else l=m;
	}
	cout<<l<<endl;
}