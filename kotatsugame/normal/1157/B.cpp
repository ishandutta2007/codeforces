#include<iostream>
using namespace std;
string s;
int n,f[114514];
main()
{
	cin>>n>>s;
	for(int i=1;i<10;i++)cin>>f[i];
	int flag=0;
	for(int i=0;i<n;i++)
	{
		int now=s[i]-'0';
		if(flag)
		{
			if(f[now]>=now)s[i]=f[now]+'0';
			else break;
		}
		else
		{
			if(f[now]>now)
			{
				flag=1;
				s[i]=f[now]+'0';
			}
		}
	}
	cout<<s<<endl;
}