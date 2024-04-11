#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n * (n + 1) / 2;
	vector <int> pref1(n, 0), pref2(n, 0);
	vector <int> post1(n, 0), post2(n, 0);
	for(int i = 0; i < s.size(); i++)
	{
		if(i == 0)
		{
			if(s[i] == 'A')
			{
				pref1[i] = 1;
				pref2[i] = 0;
			}
			else
			{
				pref1[i] = 0;
				pref2[i] = 1;
			}
		}
		else
		{
			if(s[i] == 'A')
			{
				pref1[i] = pref1[i - 1] + 1;
				pref2[i] = 0;
			}
			else
			{
				pref1[i] = 0;
				pref2[i] = pref2[i - 1] + 1;
			}
		}
	}
	for(int i = s.size()  - 1; i>= 0; i--)
	{
		if(i == s.size() - 1)
		{
			if(s[i] == 'A')
			{
				post1[i] = 1;
				post2[i] = 0;
			}
			else
			{
				post1[i] = 0;
				post2[i] = 1;
			}
		}
		else
		{
			if(s[i] == 'A')
			{
				post1[i] = 1 + post1[i + 1];
				post2[i] = 0;
			}
			else
			{
				post1[i] = 0;
				post2[i] = post2[i + 1] + 1;
			}
		}
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(i < s.size() - 1 && (s[i] == 'A' && s[i + 1] == 'B' || s[i] == 'B' && s[i + 1] == 'A'))
		{
			ans++;
		}
		if(s[i] == 'A')
		{
			if(i != 0)
			{
				ans -= pref2[i - 1];
			}
			if(i != s.size() - 1)
			{
				ans -= post2[i + 1];
			}
		}
		else
		{
			if(i != 0)
			{
				ans -= pref1[i - 1];
			}
			if(i != s.size() - 1)
			{
				ans -= post1[i + 1];
			}
		}
	}
	cout << ans - n;
	return 0;
}