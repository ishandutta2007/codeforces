#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int solve(string s1,string s2)
{
	int i=0,p,s=s2.size(),s3=s1.size()+1,lp;
	p=s1.find(s2);
	while(p!=string::npos)
	{
		if (p+s>s3)
		{
			i++;
			break;
		}
		else
		{
			s1[p+s-1]='#';
			i++;
		}
		lp=p+s-1;
		p=s1.find(s2,lp);
	}
	return i;
}
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	cout << solve(s1,s2);
}