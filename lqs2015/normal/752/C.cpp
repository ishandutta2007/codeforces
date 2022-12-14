#include<iostream>
#include<string>
using namespace std;
int n,ans;
string s;
bool u,d,r,l,f;
int main()
{
	ans=1;
	cin>>n;
	cin>>s;
	for (int i=0;i<n;i++)
	{
		if ((u && d) || (l && r))
		{
			ans++;
			u=d=l=r=0;
			if (s[i-1]=='U') u=1;
			else if (s[i-1]=='D') d=1;
			else if (s[i-1]=='L') l=1;
			else r=1;
			f=0;
		}
		if (s[i]=='U') u=1;
		else if (s[i]=='D') d=1;
		else if (s[i]=='L') l=1;
		else r=1;
	}
	if ((u && d) || (l && r)) ans++;
	cout<<ans<<endl;
	return 0;
}