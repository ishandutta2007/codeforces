#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string s2="";
		for (char c:s)
		{
			if (s2.empty() || c=='A' || s2.back()=='B')
			s2+=c;
			else
			s2.pop_back();
		}
		int b=count(s2.begin(),s2.end(),'B');
		cout << (int)s2.size()-b+b%2 << endl;
	}
}