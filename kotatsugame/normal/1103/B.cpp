#include<iostream>
using namespace std;
main()
{
	while(true)
	{
		string s;
		cin>>s;
		if(s!="start")return 0;
		int l=0,r=1000000000;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			cout<<"? "<<mid<<" "<<r<<endl;
			string s;cin>>s;
			if(s=="e")return 0;
			if(s=="x")l=mid;
			else r=mid;
		}
		int a=r;
		for(int i=2;i*i<=r;i++)if(r%i==0)
		{
			int cnt=0;
			while(r%i==0)r/=i,cnt++;
			for(int j=0;j<cnt;j++)
			{
				a/=i;
				cout<<"? 0 "<<a<<endl;
				string s;cin>>s;
				if(s=="e")return 0;
				if(s=="y")
				{
					a*=i;
					break;
				}
			}
		}
		if(r>1)
		{
			a/=r;
			cout<<"? 0 "<<a<<endl;
			string s;cin>>s;
			if(s=="e")return 0;
			if(s=="y")a*=r;
		}
		cout<<"! "<<a<<endl;
	}
}