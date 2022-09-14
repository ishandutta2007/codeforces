#include<iostream>
#include<algorithm>
using namespace std;
string s;
string L="",R="";
main()
{
	cin>>s;
	int l=0,r=s.size()-1;
	while(l+1<r-1)
	{
		if(s[l]==s[r])
		{
			L+=s[l];
			R+=s[r];
			l++;
			r--;
		}
		else if(s[l]==s[r-1])
		{
			L+=s[l];
			R+=s[r-1];
			l++;
			r-=2;
		}
		else if(s[l+1]==s[r])
		{
			L+=s[l+1];
			R+=s[r];
			l+=2;
			r--;
		}
		else
		{
			L+=s[l+1];
			R+=s[r-1];
			l+=2;
			r-=2;
		}
	}
	if(l<=r)L+=s[l];
	reverse(R.begin(),R.end());
	cout<<L<<R<<endl;
}