#include <bits/stdc++.h>
using namespace std;

string s;
int res;

bool Palin(int l, int r)
{
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++; r--;
	}
	return true;
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = i; j < s.length(); j++)
			if (!Palin(i, j)) res = max(res, j - i + 1);
	printf("%d\n", res);
	return 0;
}