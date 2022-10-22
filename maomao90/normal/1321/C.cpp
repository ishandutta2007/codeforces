#include <cstdio>

using namespace std;

int n;
char s[105];
int ans;
int l[105], r[105];
bool deleted[105];

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) l[i] = i - 1, r[i] = i + 1;
	for (char i = 'z'; i >= 'b'; i--) {
		for (int j = 0; j < n; j++) {
			if (s[j] == i) {
				if ((l[j] != -1 && s[l[j]] == i - 1) || (r[j] < n && s[r[j]] == i - 1)) {
					ans++;
					if (l[j] != -1) r[l[j]] = r[j];
					if (r[j] != -1) l[r[j]] = l[j];
					deleted[j] = true;
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
            if (deleted[j]) continue;
			if (s[j] == i) {
				if ((l[j] != -1 && s[l[j]] == i - 1) || (r[j] < n && s[r[j]] == i - 1)) {
					ans++;
					if (l[j] != -1) r[l[j]] = r[j];
					if (r[j] != -1) l[r[j]] = l[j];
					deleted[j] = true;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}