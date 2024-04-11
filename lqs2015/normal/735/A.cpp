#include<iostream>
#include<string>
using namespace std;
int n,k,pos,ans;
string s;
int main()
{
	cin>>n>>k;
	cin>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='G') pos=i;
	}
	for (int i=pos;i>=0;i-=k)
	{
		if (s[i]=='#') break;
		if (s[i]=='T') ans=1;
	}
	for (int i=pos;i<n;i+=k)
	{
		if (s[i]=='#') break;
		if (s[i]=='T') ans=1;
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}