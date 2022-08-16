#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i % 2 == 0)
		{
			s[i] = s[i] == 'a' ? 'b' : 'a';
		}
		else
		{
			s[i] = s[i] == 'z' ? 'y' : 'z';
		}
	}
	cout << s << endl;
}
 
int main()
{
	int tests;
	cin >> tests;
	while (tests--) solve();
	return 0;
}