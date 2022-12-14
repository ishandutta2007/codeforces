#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<map>
using namespace std;
int n,l,r,mn;
char s[111111];
set<char> se,sta;
map<char,int> mp;
/*bool check()
{
	for (set<char>::iterator it=sta.begin();it!=sta.end();it++)
	{
		if (se.find(*it)==se.end()) return 0;
	}
	return 1;
}*/
const int Inf=2000000;
int main()
{
	mn=Inf;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		sta.insert(s[i]); 
	}
	for (;r<n;)
	{ 
		while(mp[s[l]]<=1 && r<n)
		{
			if (se==sta)
			{
				mn=min(mn,r-l);
			}
			mp[s[r]]++;
			se.insert(s[r++]);
		}
		while (mp[s[l]]>1)
		{
			mp[s[l]]--;
			l++;
		}
	}
	if (se==sta) mn=min(mn,r-l);
	if (mn==Inf) mn=n;
	cout<<mn<<endl;
	return 0;
}