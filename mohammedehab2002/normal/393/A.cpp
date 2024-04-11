#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
int main()
{
	int i,a,b,c,d,ans;
	map <char,int> m;
	m['n']=0;
	m['i']=0;
	m['e']=0;
	m['t']=0;
	string s;
	cin >> s;
	for (i=0;i<s.size();i++)
	m[s[i]]++;
	a=(m['n']-1)/2;
	b=m['i'];
	c=m['e']/3;
	d=m['t'];
	ans=min(min(a,b),min(c,d));
	if (ans==0)
	{
		if (b==0 || c==0 || d==0)
		cout << 0;
		else
		{
			if (m['n']==3)
			cout << 1;
			else
			cout << 0;
		}
	}
	else
	cout << ans;
}