#include<iostream>
using namespace std;
int M;
string s;
main()
{
	cin>>s>>M;
	for(;M--;)
	{
		int l,r,k;cin>>l>>r>>k;
		l--;
		int len=r-l;
		string t=s.substr(l,len);
		for(int i=0;i<len;i++)s[l+(i+k)%len]=t[i];
	}
	cout<<s<<endl;
}