#include <iostream>
#include <string.h>
#include <map>
using namespace std;
map<string,int> m;
int main()
{
	int a,b,c=0;
	cin >> a >> b;
	for (int i=0;i<a;i++)
	{
		string s;
		cin >> s;
		m[s]=1;
	}
	for (int i=0;i<b;i++)
	{
		string s;
		cin >> s;
		c+=m[s];
	}
	a-=c/2;
	b-=c/2;
	if (c%2)
	b--;
	if (b>=a)
	cout << "NO";
	else
	cout << "YES";
}