#include <cstdio>
#include <iostream>
using namespace std;

string s;
bool ab, ba;

bool Find(const string &nd, int from)
{
	for (int i = from; i + 1 < s.length(); i++)
		if (s[i] == nd[0] && s[i + 1] == nd[1]) return true;
	return false;
}

int main()
{
	cin >> s;
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] == 'A' && s[i + 1] == 'B') {
			if (Find("BA", i + 2)) { printf("YES\n"); return 0; }
			break;
		}
	for (int i = 0; i + 1 < s.length(); i++)
		if (s[i] == 'B' && s[i + 1] == 'A') {
			if (Find("AB", i + 2)) { printf("YES\n"); return 0; }
			break;
		}
	printf("NO\n");
	return 0;
}