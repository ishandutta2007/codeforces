#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,m,a;
	int de[100],co=0;
	string s[100];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<m;i++)
	{
		cin>>a;
		a--;
		de[co]=a;
		co++;
	}
	for(int i=1;i<m;i++)
	{
		if(s[de[i]].length()!=s[de[i-1]].length())
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	string ans=s[de[0]];
	int len=ans.length();
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(ans[j]!='?'&&ans[j]!=s[de[i]][j])
			{
				ans[j]='?';
			}
		}
	}
	co=0;
	bool flag;
	for(int i=0;i<n;i++)
	{
		if(i==de[co])
		{
			co++;
			continue;
		}
		if((int)s[i].length()!=len)continue;
		flag=false;
		for(int j=0;j<len;j++)
		{
			if(ans[j]!='?'&&s[i][j]!=ans[j])
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	cout<<ans<<endl;
	return 0;
}