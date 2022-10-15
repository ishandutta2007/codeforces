#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second
const int N = 5e5 + 5;
int n;
char s[N];
int sg[N];
void work() {
	
	scanf("%d", &n);
	scanf("%s", s + 1);
	int cnt = 0, a = 0, b = 0;
	for (int i = 1; i<= n; i++) if (s[i] == 'R') a++; else b++;
	if (a != b) {
		puts (a > b ? "Alice" : "Bob");
		return;
	}
	for (int i = 1; i <= n;) {
		int j = i + 1;
		while (j <= n && s[j] != s[j - 1]) j++;
		cnt ^= sg[j - i];
		i = j;
	}
	puts (cnt ? "Alice" : "Bob");
}

int w[N];

int main() {
	memset(sg, 0, sizeof sg);
	sg[1] = 0;
	sg[2] = sg[3] = 1;
	for (int i = 4; i < N; i++) {
		int upper = min(i - 2, 511);
		for (int j = 0; j <= upper; j++) {
			w[sg[j] ^ sg[i - j - 2]] = i;
		}
		for (int k = 0; ; k++) {
			if (w[k] != i) {
				sg[i] = k;
				break;
			}
		}
	}
	int T;
	read(T);
	while (T--) work();
}