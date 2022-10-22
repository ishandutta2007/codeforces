#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
string s;

bool Check(int zer)
{
	int lst = -100;
	for (int i = 0; i < s.length(); i++)
		if ((i < zer) ^ (s[i] == '0')) {
			if (lst + 1 >= i) return false;
			lst = i;
		}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		cin >> s;
		int pnt = 0;
		while (pnt <= s.length() && !Check(pnt)) pnt++;
		printf("%s\n", pnt <= s.length()? "YES": "NO");
	}
    return 0;
}