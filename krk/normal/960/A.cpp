#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[3];

int main()
{
	cin >> s;
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] > s[i + 1]) { printf("NO\n"); return 0; }
	for (int i = 0; i < s.length(); i++)
		cnt[s[i] - 'a']++;
	if (cnt[2] == cnt[0] || cnt[2] == cnt[1]) 
		if (cnt[0] > 0 && cnt[1] > 0) printf("YES\n");
		else printf("NO\n");
	else printf("NO\n");
	return 0;
}