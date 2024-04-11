#include <iostream>
#include <string.h>
#include <map>
using namespace std;
map<string,bool> m;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (m[s])
		cout << "YES\n";
		else
		cout << "NO\n";
		m[s]=1;
	}
}