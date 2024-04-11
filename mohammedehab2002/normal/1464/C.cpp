#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int main()
{
	int n;
	string s;
	long long t;
	cin >> n >> t >> s;
	t-=(1<<(s.back()-'a'));
	s.pop_back();
	t+=(1<<(s.back()-'a'));
	s.pop_back();
	for (char c:s)
	cnt[c-'a']++;
	for (int i=25;i>=0;i--)
	{
		while (cnt[i]--)
		{
			if (t>0)
			t-=(1<<i);
			else
			t+=(1<<i);
		}
	}
	cout << (t? "No":"Yes");
}