#include<iostream>
#include<string>
using namespace std;
string s;
int pos,cnt,n;
int main()
{
	cin>>n>>s;
	pos=0;
	while(pos<n)
	{
		cnt=0;
		while(pos<n && s[pos]=='1') 
		{
			pos++;
			cnt++;
		}
		cout<<cnt;
		pos++;
	}
	if (s[n-1]=='0') cout<<0;
	cout<<endl;
	return 0;
}