#include <bits/stdc++.h>
using namespace std;

int t;
int n;
bool song[200005];

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(song, 0, sizeof song);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			if (song[x]) song[x + 1] = true;
			else song[x] = true;
		}
		int cnt = 0;
		for (int i = 0; i <= 2 * n + 5; i++) {
			if (song[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}