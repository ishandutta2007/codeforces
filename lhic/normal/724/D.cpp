#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int m;
char s[120000];
int n;
int us[120000];

int main() {
	scanf("%d", &m);
	scanf(" %s", s);
	n = strlen(s);
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < n; ++j)
			if (s[j] == 'a' + i)
				us[j] = 2;
		int pr = -1;
		int lst = - m - 100;
		int fl = 0;
		for (int j = 0; j < n; ++j) {
			if (us[j] == 1) {
				if (j - pr <= m) {
					pr = j;
					continue;
				}
				if (j - lst <= m) {
					us[lst] = 1;
					pr = j;
				}
				else {
					fl = 1;
					break;
				}
			}
			else if (us[j] == 2) {
				if (j - pr <= m) {
					lst = j;
				}
				else if (j - lst <= m) {
					us[lst] = 1;
					pr = lst;
					lst = j;
				}
				else {
					fl = 1;
					break;
				}
			}
		}
		if (!fl && pr + m < n) {
			if (lst + m >= n) {
				us[lst] = 1;
			}
			else {
				fl = 1;
			}
		}
		if (fl) {
			for (int j = 0; j < n; ++j)
				if (us[j])
					us[j] = 1;
		}
		else {
			string ans;
			for (int i = 0; i < n; ++i)
				if (us[i] == 1)
					ans += s[i];
			sort(ans.begin(), ans.end());
			cout << ans << "\n";
			return 0;
		}
	}
	return 0;
}