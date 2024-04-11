#include <bits/stdc++.h>
using namespace std;

int t;
int n;
string s;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cin >> s;
		int lef = 0, rig = int(s.length()) - 1;
		bool ok = true;
		while (lef < rig && ok) {
			int a = s[lef] - 'a';
			int b = s[rig] - 'a';
			ok = abs(a - b) == 0 || abs(a - b) == 2;
			lef++; rig--;
		}
		printf("%s\n", ok? "YES": "NO");
	}
	return 0;
}