#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}
const int N = 1e5 + 5;
char s[N];
int main() {
	int T;
	read(T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		int ans = 0, ans2 = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') ans = 1;
			if (s[i] == '1') ans2 = 1;
			if (s[i] == '0' && (i == 0 || s[i - 1] != '0')) cnt++;
		}
		if (!ans) {
			puts("0");
			continue;
		}
		if (!ans2 || cnt == 1) {
			puts("1");
			continue;
		}
		puts("2");
	}
}