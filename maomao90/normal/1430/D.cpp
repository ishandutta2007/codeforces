#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[200005];
vector <int> rep;
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(s, 0, sizeof s);
		scanf("%d", &n);
		scanf(" %s", s);
		rep.clear();
		ans = 0;
		char prv = s[0];
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (i == n || s[i] != prv) {
				rep.push_back(cnt);
				cnt = 0;
			}
			cnt++;
			if (i != n) prv = s[i];
		}
		int pnt = 0;
		for (int i = 0; i < rep.size(); i++) {
			if (rep[i] == 1) {
				pnt = max(i + 1, pnt);
				while (pnt < rep.size() && rep[pnt] == 1) pnt++;
				if (pnt >= rep.size()) {
					ans += (rep.size() - i + 1) / 2;
					break;
				}
				rep[pnt]--;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}