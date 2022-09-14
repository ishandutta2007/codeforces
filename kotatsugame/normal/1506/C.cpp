#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string a,b;
		cin>>a>>b;
		int ans=a.size()+b.size();
		for(int i=0;i<a.size();i++)for(int j=1;i+j<=a.size();j++)
		{
			string x=a.substr(i,j);
			for(int k=0;k+j<=b.size();k++)
			{
				if(x==b.substr(k,j))
				{
					int now=i+(a.size()-i-j)+k+(b.size()-k-j);
					if(ans>now)ans=now;
				}
			}
		}
		cout<<ans<<endl;
	}
}