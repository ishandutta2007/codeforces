#include <iostream>
#include <string.h>
using namespace std;
int dif(string s,string a)
{
	int i,ans=0;
	for (i=0;i<s.size();i++)
	{
		if (s[i]!=a[i])
		ans++;
	}
	return ans;
}
int main()
{
	int i,x,c=0,ans;
	string s,a;
	cin >> s >> a;
	ans=dif(s,a);
	if (ans%2)
	{
		cout << "impossible";
		return 0;
	}
	for (i=0;c<ans/2;i++)
	{
		if (s[i]!=a[i])
		c++;
		cout << s[i];
	}
	for (x=i;x<s.size();x++)
	cout << a[x];
}