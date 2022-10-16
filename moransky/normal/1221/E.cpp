// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int a, b, n, c, d, f;

char s[N];

bool o, wi;

void inline add(int x) {
	if (x >= b && x < a) o = 1;
	if (x >= a && x < 2 * b) d++;
	if (x >= 2 * b) {
		c++;
		f = x - a;
	}
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(a), read(b); scanf("%s", s + 1);
		n = strlen(s + 1); o = c = d = wi = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'X') continue;
			int j = i;
			while (j < n && s[j + 1] == s[i]) ++j;
			add(j - i + 1);
			i = j;
		}
		if (c > 1) o = 1;
		if (o) puts("NO");
		else if (!c) puts((d & 1) ? "YES" : "NO");
		else {
			if (f <= 2 * (b - 1) && (d % 2 == 0)) wi = 1;
			if (a <= f && f <= b - 1 + 2 * b - 1 && (d & 1)) wi = 1;
			if (2 * a <= f && f <= 2 * (2 * b - 1) && (d % 2 == 0)) wi = 1; 
			puts(wi ? "YES" : "NO");
		}
	}
	return 0;
}