#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
int pos;
int func(string s,int p,int ps)
{
	if (p==s.size())
	{
		if (ps==pos)
		return 1;
		else
		return 0;
	}
	if (s[p]=='+')
	return func(s,p+1,ps+1);
	else if (s[p]=='-')
	return func(s,p+1,ps-1);
	else
	return func(s,p+1,ps+1)+func(s,p+1,ps-1);
}
int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	pos=count(s1.begin(),s1.end(),'+');
	pos=pos-(s1.size()-pos);
	int prop=count(s2.begin(),s2.end(),'?');
	prop=(1<<prop);
	cout << setprecision(12);
	cout << fixed << (double)func(s2,0,0)/prop;
}