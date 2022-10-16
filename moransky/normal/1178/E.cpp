// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e6 + 5;

int n, t;

char s[N], a[N];

char op = '?';

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int l = 1, r = n;
	while (l <= r) {
		if (r - l + 1 <= 3) {
			op = s[l];
			break;
		}
		if (s[l] == s[r] || s[l] == s[r - 1]) a[++t] = s[l];
		else a[++t] = s[l + 1];
		l += 2, r -= 2;
	}
	printf("%s", a + 1);
	reverse(a + 1, a + 1 + t);
	if (op != '?') putchar(op);
	printf("%s\n", a + 1);
    return 0;
}