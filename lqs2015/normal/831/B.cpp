#include<iostream>
#include<string>
using namespace std;
string s,a,b;
int main()
{
	cin>>a>>b>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9') cout<<s[i];
		else if (s[i]>='A' && s[i]<='Z')
		{
			for (int j=0;j<26;j++)
			{
				if (a[j]-32==s[i]) cout<<(char)(b[j]-32);
			}
		}
		else
		{
			for (int j=0;j<26;j++)
			{
				if (a[j]==s[i]) cout<<b[j];
			}
		} 
	}
	cout<<endl;
	return 0;
}