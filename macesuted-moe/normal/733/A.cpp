#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans=1,maxx=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
		{
			maxx=max(maxx,ans);
			ans=1;
		}
		else ans++;
	cout<<max(maxx,ans);
	return 0;
}