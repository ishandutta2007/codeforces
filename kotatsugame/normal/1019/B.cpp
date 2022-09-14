#include<iostream>
using namespace std;
int N;
int ask(int k)
{
	cout<<"? "<<k+1<<endl;
	int x;cin>>x;
	cout<<"? "<<k+1+N/2<<endl;
	int y;cin>>y;
	return x-y;
}
main()
{
	cin>>N;
	int L=ask(0);
	int R=-L;
	if(L%2==1)
	{
		cout<<"! -1"<<endl;
		return 0;
	}
	if(L==0)
	{
		cout<<"! 1"<<endl;
		return 0;
	}
	int l=0,r=N/2;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		int now=ask(mid);
		if(now==0)
		{
			cout<<"! "<<mid+1<<endl;
			return 0;
		}
		if(now>0)
		{
			if(L>0)
			{
				L=now;
				l=mid;
			}
			else
			{
				R=now;
				r=mid;
			}
		}
		else
		{
			if(L>0)
			{
				R=now;
				r=mid;
			}
			else
			{
				L=now;
				l=mid;
			}
		}
	}
	cout<<"! -1"<<endl;
}