#include<iostream>
using namespace std;

int main()
{
	int n,flag=0,count=0,ans[50],anscount=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='W')
		{
			if(flag==1)
			{
				ans[anscount]=count;
				count=0;
				anscount++;
				flag=0;
			}
		}
		else
		{
			flag=1;
			count++;
		}
	}
	if(flag==1)
	{
		ans[anscount]=count;
		anscount++;
	}
	cout<<anscount<<endl;
	for(int i=0;i<anscount;i++)
	{
		if(i)cout<<" ";
		cout<<ans[i];
	}
	if(anscount)cout<<endl;
	return 0;
}