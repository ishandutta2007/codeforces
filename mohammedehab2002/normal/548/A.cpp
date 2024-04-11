#include <iostream>
#include <set>
using namespace std;
bool pal(string s)
{
	for (int i=0;i<s.size();i++)
	{
		if (s[i]!=s[s.size()-i-1])
		return 0;
	}
	return 1;
}
int main()
{
	string s;
	int k;
	cin >> s >> k;
	if (s.size()%k)
	{
		cout << "NO";
		return 0;
	}
	for (int i=0;i<s.size();i+=s.size()/k)
	{
		if (!pal(s.substr(i,s.size()/k)))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}