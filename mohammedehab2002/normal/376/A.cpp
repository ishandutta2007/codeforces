#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int main()
{
	long long i,s1=0,s2=0,l1=0,l2,pos,test=0;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='^')
		{
			pos=i;
			break;
		}
		l1++;
	}
	l2=s.size()-pos-1;
	for (i=0;i<pos;i++)
	{
		if (isdigit(s[i]))
		s1+=(long long)(s[i]-'1'+1)*(pos-i);
	}
	for (i=pos+1;i<s.size();i++)
	{
		if (isdigit(s[i]))
		s2+=(long long)(s[i]-'1'+1)*(i-pos);
	}
	if (s1<s2)
	cout << "right";
	else if (s1==s2)
	cout << "balance";
	else
	cout << "left";
}