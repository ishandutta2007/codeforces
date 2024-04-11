#include <iostream>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	map <string,string> s;
	string a,b;
	int n,m,i;
	cin >> n >> m;
	for (i=0;i<m;i++)
	{
		cin >> a >> b;
		if (b.size()<a.size())
		s[a]=b;
		else
		s[a]=a;
	}
	for (i=0;i<n;i++)
	{
		cin >> a;
		cout << s[a] << ' ';
	}
}