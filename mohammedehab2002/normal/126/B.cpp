#include <iostream>
using namespace std;
int z[1000005];
int main()
{
	string s;
	cin >> s;
	int l=0,r=0;
	for (int i=1;i<s.size();i++)
	{
		if (i>r)
		{
			l=r=i;
			while (r<s.size() && s[r]==s[r-l])
			r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if (z[k]<r-i+1)
			z[i]=z[k];
			else
			{
				l=i;
				while (r<s.size() && s[r]==s[r-l])
				r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	int mx=0;
	for (int i=1;i<s.size();i++)
	{
		if (i+z[i]==s.size())
		mx=max(mx,z[i]-1);
		else
		mx=max(mx,z[i]);
	}
	int ans=-1;
	for (int i=1;i<s.size();i++)
	{
		if (i+z[i]==s.size() && z[i]<=mx)
		ans=max(ans,z[i]);
	}
	if (ans==-1)
	cout << "Just a legend";
	else
	cout << s.substr(s.size()-ans,ans);
}