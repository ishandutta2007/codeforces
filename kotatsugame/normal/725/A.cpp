#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int i;
	for(i=0;i<n;i++)if(s[i]!='<')break;
	int sum=i;
	for(i=n-1;i>=0;i--)if(s[i]!='>')break;
	sum+=n-1-i;
	cout<<sum<<endl;
	return 0;
}