#include<iostream>
#include<string>
using namespace std;
int k,cnt[11];
string s[11];
int main()
{
	cin>>k;
	for (int i=0;i<4;i++)
	{
		cin>>s[i];
	}
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			if (isdigit(s[i][j])) cnt[s[i][j]-'0']++;
		}
	}
	for (int i=0;i<=9;i++)
	{
		if (cnt[i]>2*k) 
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}