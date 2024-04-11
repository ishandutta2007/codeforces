#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;

int main()
{
	scanf("%d %d", &n, &m);
	cin >> s;
	cin >> t;
	bool has = false;
	int ind;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '*') { has = true; ind = i; }
	if (!has) {
		printf("%s\n", s == t? "YES": "NO");
		return 0;
	}
	if (int(s.length()) - 1 > int(t.length())) { printf("NO\n"); return 0; }
	for (int i = 0; i < ind; i++)
		if (s[i] != t[i]) { printf("NO\n"); return 0; }
	for (int i = 1; i < int(s.length()) - ind; i++)
		if (s[int(s.length()) - i] != t[int(t.length()) - i]) { printf("NO\n"); return 0; }
	printf("YES\n");
	return 0;
}