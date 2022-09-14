#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int h,c,t;cin>>h>>c>>t;
		h-=t;
		c-=t;
		if(h+c>=0)
		{
			cout<<2<<"\n";
		}
		else
		{
			long long k1=h/-(h+c),k2=k1+1;
			int ans;
			if(abs((h+c)*k1+h)*(2*k2+1)>abs((h+c)*k2+h)*(2*k1+1))ans=k2;
			else ans=k1;
			if(2*ans+1==1)
			{
				if(abs((h+c)*ans+h)*2>abs(h+c)*(2*ans+1))cout<<2<<"\n";
				else cout<<2*ans+1<<"\n";
			}
			else
			{
				if(abs((h+c)*ans+h)*2>=abs(h+c)*(2*ans+1))cout<<2<<"\n";
				else cout<<2*ans+1<<"\n";
			}
		}
	}
}