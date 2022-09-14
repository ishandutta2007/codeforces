#include<iostream>
using namespace std;
int a,b,x;
main()
{
	cin>>a>>b>>x;
	string ans="";
	if(a>b)
	{
		ans+='0';
		a--;
		for(int i=0;i<x;i++)
		{
			if(i%2==0)
			{
				ans+='1';
				b--;
			}
			else
			{
				ans+='0';
				a--;
			}
		}
	}
	else
	{
		ans+='1';
		b--;
		for(int i=0;i<x;i++)
		{
			if(i%2==0)
			{
				ans+='0';
				a--;
			}
			else
			{
				ans+='1';
				b--;
			}
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]=='0')
		{
			while(a>0)cout<<0,a--;
		}
		else
		{
			while(b>0)cout<<1,b--;
		}
		cout<<ans[i];
	}
	cout<<endl;
}