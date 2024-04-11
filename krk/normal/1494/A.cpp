#include <bits/stdc++.h>
using namespace std;

string ch = "()";

int T;
string s;

bool Solve(char a, char b, char c)
{
	int st = 0;
	for (int i = 0; i < s.length(); i++) {
		char my;
		if (s[i] == 'A') my = a;
		else if (s[i] == 'B') my = b;
		else if (s[i] == 'C') my = c;
		if (my == '(') st++;
		else st--;
		if (st < 0) return false;
	}
	return st == 0;
}

bool Solve()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				if (Solve(ch[i], ch[j], ch[k]))
					return true;
	return false;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> s;
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}