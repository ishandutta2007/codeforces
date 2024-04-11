#include<iostream>
using namespace std;
int n;
string s[555];
int cnt;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=1;i<n-1;i++)for(int j=1;j<n-1;j++)
	{
		if(s[i][j]=='X'&&s[i-1][j-1]=='X'&&s[i-1][j+1]=='X'&&s[i+1][j-1]=='X'&&s[i+1][j+1]=='X')cnt++;
	}
	cout<<cnt<<endl;
}