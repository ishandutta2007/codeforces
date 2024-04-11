#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
	cin >> t;
	while (t--) {
		cin >> s;
		if (s.length() % 2) { printf("NO\n"); continue; }
		int pl = 0, neut = 0, mn = 0;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '(') pl++;
			else if (s[i] == ')') mn++;
			else neut++;
		if (pl > s.length() / 2 || mn > s.length() / 2) { printf("NO\n"); continue; }
		int st = 0;
		bool fall = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '?')
				if (pl < s.length() / 2) { pl++; s[i] = '('; }
				else { mn++; s[i] == ')'; }
			if (s[i] == '(') st++;
			else st--;
			if (st < 0) fall = true;
		}
		printf("%s\n", fall? "NO": "YES");
	}
    return 0;
}