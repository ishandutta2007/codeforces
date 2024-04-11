#include<iostream>
using namespace std;
main()
{
	int minc=1e9;
	int n;cin>>n;
	string s[50],t[50];
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)t[i]=s[i]+s[i];
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(i==j)continue;
			int k=0;
			for(;k<=(int)t[j].size()-(int)s[i].size();k++)
			{
				if(t[j].substr(k,s[i].size())==s[i])break;
			}
			if(k>(int)t[j].size()-(int)s[i].size())
			{
				cnt=-1;
				break;
			}
			else cnt+=k;
		}
		if(cnt>=0)minc=minc>cnt?cnt:minc;
	}
	cout<<(minc==1e9?-1:minc)<<endl;
}