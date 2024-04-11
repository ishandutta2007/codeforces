#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
	cin >> s;
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] == '1' && s[i + 1] == '1') { printf("No\n"); return 0; }
	for (int i = 0; i < s.length(); i++) if (s[i] == '0') {
		s[i] = '1';
		bool ok = true;
		for (int j = 0; j + 1 < s.length(); j++)
			if (s[j] == '1' && s[j + 1] == '1') ok = false;
		if (ok) { printf("No\n"); return 0; }
		s[i] = '0';
	}
	printf("Yes\n");
	return 0;
}