#include<iostream>
#include<string>
using namespace std;
int n,o;
string s;
int main()
{
	cin>>n>>s;
	for (int i=0;i<n-1;i++)
	{
		if (s[i]=='S' && s[i+1]=='F') o++;
		if (s[i]=='F' && s[i+1]=='S') o--;
	}
	if (o>0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}