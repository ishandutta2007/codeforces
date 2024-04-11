#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

string s;
int freq[Maxn][3];
int m;

int main()
{
	getline(cin, s);
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j < 3; j++)
			freq[i][j] = freq[i - 1][j];
		freq[i][s[i - 1] - 'x']++;
	}
	scanf("%d", &m);
	while (m--) {
		int l, r; scanf("%d %d", &l, &r);
		int mn = Maxn, mx = 0;
		for (int j = 0; j < 3; j++) {
			mn = min(mn, freq[r][j] - freq[l - 1][j]);
			mx = max(mx, freq[r][j] - freq[l - 1][j]);
		}
		printf("%s\n", r - l + 1 < 3 || mx - mn <= 1? "YES": "NO");
	}
	return 0;
}