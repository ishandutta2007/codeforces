#include<iostream>
#include<string>
using namespace std;
int ch[29],n,k;
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	for (int i=0;i<n;i++)
	{
		ch[s[i]-'a']++;
	}
	for (int i=0;i<26;i++)
	{
		if (ch[i]>k) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}