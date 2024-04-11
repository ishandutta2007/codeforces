#include<bits/stdc++.h>
using namespace std;
string s,t,ans,cur;
int main()
{
	cin>>s>>t;
	ans="";
	for (int i=0;i<s.size();i++)
	{
		for (int j=0;j<t.size();j++)
		{
			cur="";
			for (int k=0;k<=i;k++) cur.push_back(s[k]);
			for (int k=0;k<=j;k++) cur.push_back(t[k]);
			if (ans=="" || ans>cur) ans=cur; 
		}
	}
	cout<<ans<<endl;
	return 0;
}