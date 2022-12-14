#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n;
string s,ns;
bool f;
bool isp(string &s)
{
	for (int i=0;i<n;i++)
	{
		if (s[i]!=s[n-1-i]) return 0;
	}
	return 1;
}
int main()
{
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++)
	{
		if ((n&1) && i==n/2) continue;
		if (s[i]!=s[0])
		{
			f=1;
			break;
		}
	}
	if (!f) 
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i=0;i<n-1;i++)
	{
		ns=s.substr(i+1)+s.substr(0,i+1);
		if (ns==s) continue;
		if (isp(ns))
		{
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
	return Accepted;
}