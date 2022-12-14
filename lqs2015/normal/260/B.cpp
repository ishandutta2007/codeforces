#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
map<string,int> mp;
string s,f,ans;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d,m,y;
int main()
{
	cin>>s;
	f="dd-mm-yyyy";
	int n=s.size(),fn=f.size();
	for (int i=0;i<=n-fn;i++)
	{
		string now=s.substr(i,fn);
		bool flag=0;
		for (int i=0;i<fn;i++)
		{
			if (f[i]!='-' && !isdigit(now[i])) flag=1;
			if (f[i]=='-' && now[i]!='-') flag=1; 
		}
		if (!flag)
		{
			if (sscanf(now.c_str(),"%2d-%2d-%4d",&d,&m,&y)==3)
			{
				if (1<=m && m<=12 && d>=1 && d<=days[m] && y>=2013 && y<=2015)
				{
					mp[now]++;
				}
			}
		}
	}
	ans=mp.begin()->first;
	for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if (it->second>mp[ans]) ans=it->first;
	}
	cout<<ans<<endl;
	return 0;
}