#include <bits/stdc++.h>
using namespace std;

const int Maxl = 1005;

int q;
string s, t;
char res[Maxl];
int rlen;

bool Solve()
{
	rlen = 0;
	int i = 0, j = 0;
	do {
		if (s[i] != t[j]) return false;
		res[rlen++] = s[i];
		i = (i + 1) % int(s.length());
		j = (j + 1) % int(t.length());
		if (i == 0 && j == 0) return true;
	} while (true);
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		cin >> s;
		cin >> t;
		if (Solve()) {
			res[rlen] = '\0';
			printf("%s\n", res);
		} else printf("-1\n");
	}
    return 0;
}