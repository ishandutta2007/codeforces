#include<iostream>
#include<algorithm>
using namespace std;
string s[3];
bool f(string a,string b){return a[0]==b[0]&&a[1]+1==b[1];}
main()
{
	for(int i=0;i<3;i++)
	{
		cin>>s[i];
		swap(s[i][0],s[i][1]);
	}
	sort(s,s+3);
	int ans=2;
	if(s[0]==s[1])
	{
		if(s[1]==s[2])ans=0;
		else ans=1;
	}
	else if(s[1]==s[2])ans=1;
	if(f(s[0],s[1]))
	{
		if(f(s[1],s[2]))ans=0;
		else ans=min(ans,1);
	}
	else if(f(s[1],s[2]))ans=min(ans,1);
	if(s[0][0]==s[1][0]&&s[0][1]+2==s[1][1])ans=min(ans,1);
	if(s[1][0]==s[2][0]&&s[1][1]+2==s[2][1])ans=min(ans,1);
	cout<<ans<<endl;
}