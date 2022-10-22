#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int l=0,r=0,u=0,d=0,ans=0,all;
	cin>>s;
	int sl=s.length();
	if(sl%2==1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=0;i<sl;i++)
	{
		if(s[i]=='U')
		{
			u++;
		}
		if(s[i]=='D')
		{
			d++;
		}
		if(s[i]=='L')
		{
			l++;
		}
		if(s[i]=='R')
		{
			r++;
		}
	}
	ans=max(abs(u+l-d-r)/2,abs(u+r-d-l)/2);
	cout<<ans<<endl;
}