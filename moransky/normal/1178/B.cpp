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

int n, L[N], R[N];

char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int w = 0;
	for (int i = 2; i <= n; i++) {
		if (s[i] == 'v' && s[i - 1] == 'v') w++;
		if (s[i] == 'o') L[i] = w; 
	}
	w = 0;
	for (int i = n - 1; i; i--) {
		if (s[i] == 'v' && s[i + 1] == 'v') w++;
		if (s[i] == 'o') R[i] = w; 
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += (LL)L[i] * R[i];
	printf("%lld\n", ans);
    return 0;
}