#include <bits/stdc++.h>
using namespace std;


char s[12312];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; ) {
			if (s[i] == '1') {
				i++;
				continue;
			}
			int j = i;
			while (s[j] == '0') {
				j++;
			}
			if (j > n && i == 1) break;
			int l = i, r = j - 1, cnt = 0;
			if (i == 1) {
				while (r > 0 && cnt < m) {
					s[r] = '1';
					r--;
					cnt ++;
				}
			} else if (j > n) {
				while (l <= n && cnt < m) {
					s[l] = '1';
					l++;
					cnt ++;
				}
			} else {
				while (l < r && cnt < m) {
					s[l] = '1';
					s[r] = '1';
					l ++, r --;
					cnt ++;
				}
			}
			i = j ;
		}
		puts(s + 1);
	}

}