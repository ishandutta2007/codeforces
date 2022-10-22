#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int Maxn = 105;

int n;
string s[Maxn];
int res;

bool Check(const string &s, char a, char b)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] != a && s[i] != b) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (char a = 'a'; a <= 'z'; a++)
		for (char b = 'a'; b <= 'z'; b++) {
			int cur = 0;
			for (int i = 0; i < n; i++)
				if (Check(s[i], a, b)) cur += s[i].length();
			res = max(res, cur);
		}
	printf("%d\n", res);
	return 0;
}