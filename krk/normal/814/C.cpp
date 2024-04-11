#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxl = 26;
const int Maxn = 2005;

int n;
string s;
bool was[Maxl];
int got[Maxl][Maxn];
int q;

int main()
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		was[s[i] - 'a'] = true;
		int nd = 0;
		for (int j = i; j < s.length(); j++) {
			if (s[j] != s[i]) nd++;
			got[s[i] - 'a'][nd] = max(got[s[i] - 'a'][nd], j - i + 1);
		}
		for (int j = i - 1; j >= 0; j--) {
			if (s[j] != s[i]) nd++;
			got[s[i] - 'a'][nd] = max(got[s[i] - 'a'][nd], int(s.length()) - j);
		}
	}
	for (int i = 0; i < Maxl; i++) if (was[i])
		for (int j = 1; j < Maxn; j++)
			got[i][j] = max(got[i][j - 1], got[i][j]);
	scanf("%d", &q);
	while (q--) {
		int n; char ch; scanf("%d %c", &n, &ch);
		if (!was[ch - 'a']) printf("%d\n", n);
		else printf("%d\n", got[ch - 'a'][n]);
	}
	return 0;
}