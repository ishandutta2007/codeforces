#include<iostream>
using namespace std;
int t,n;
string s;
main()
{
	cin>>t;
	for(;t--;)
	{
		cin>>n>>s;
		int id=0;
		while(id+1<n&&s[id]==s[id+1])id++;
		if(id+1==n)cout<<"-1 -1\n";
		else cout<<id+1<<" "<<id+2<<"\n";
	}
}