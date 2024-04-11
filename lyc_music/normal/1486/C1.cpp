#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,r,pos,now,mid,ans;
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	cin>>pos;
	if (pos==1) now=0; else
	if (pos==n) now=n; else
	{
	cout<<"? 1 "<<pos<<endl;
	cin>>now;}
	if(now!=pos)
	{
		l=pos+1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			cout<<"? "<<pos<<' '<<mid<<endl;
			cin>>now;
			if(now==pos)
			{
				r=mid;
			}
			else 
			{
				l=mid+1;
			}
		}
		cout<<"! "<<r<<endl;
	}
	else
	{
		l=1;
		r=pos-1;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			cout<<"? "<<mid<<' '<<pos<<endl;
			cin>>now;
			if(now==pos)
			{
				l=mid;
			}
			else 
			{
				r=mid-1;
			}
		}
		cout<<"! "<<l<<endl;
	}
	return 0;
}