#include<iostream>
using namespace std;
main()
{
	string s;cin>>s;
	int n=s.size(),cnt=0;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1])cnt++;
	}
	cout<<(cnt==1||cnt==0&&n%2==1?"YES":"NO")<<endl;
}