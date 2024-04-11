#include<iostream>
using namespace std;
int n,m;string s;
main()
{
	cin>>n>>m>>s;
	int l,r;char a,b;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r>>a>>b;
		for(int j=l-1;j<r;j++)if(s[j]==a)s[j]=b;
	}
	cout<<s<<endl;
}