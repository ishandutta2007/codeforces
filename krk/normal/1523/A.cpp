#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, m;
char str[Maxn];
char res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		scanf("%s", str);
		for (int i = 0; i < n; i++) {
			res[i] = str[i];
			if (str[i] == '0') {
				int lef = i - 1;
				int rig = i + 1;
				while (lef >= 0 && str[lef] == '0') lef--;
				while (rig < n && str[rig] == '0') rig++;
				if (lef >= 0 && rig < n) {
					int mn = min(abs(i - lef), abs(i - rig));
					int mx = max(abs(i - lef), abs(i - rig));
					if (mn <= m && mn != mx) res[i] = '1';
				} else if (lef >= 0) {
					if (abs(i - lef) <= m) res[i] = '1';
				} else if (rig < n) {
					if (abs(i - rig) <= m) res[i] = '1';
				}
			}
		}
		res[n] = '\0';
		printf("%s\n", res);
	}
    return 0;
}