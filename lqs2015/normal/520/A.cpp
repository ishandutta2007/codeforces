#include<iostream>
#include<string>
using namespace std;
string s;
int n;
bool u[27];
int main()
{
	cin>>n>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]>='A' && s[i]<='Z') s[i]+=32;
		u[s[i]-'a']=1;
	}
	for (int i=0;i<26;i++)
	{
		if (!u[i]) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}