#include<iostream>
#include<string>
using namespace std;
string s,str[111];
int n;
int f[2];
int main()
{
	cin>>s>>n;
	for (int i=1;i<=n;i++) cin>>str[i];
	for (int i=1;i<=n;i++)
	{
		if (str[i]==s) 
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (str[i][1]==s[0]) f[0]++;
		if (str[i][0]==s[1]) f[1]++;
	}
	if (f[0] && f[1]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}