// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, a[N], cnt[30];
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 0; i < 30; i++) {
			cnt[i] = 0;
			for (int j = 1; j <= n; j++)
				cnt[i] += a[j] >> i & 1;
		}
		for (int i = 1; i <= n; i++) {
			bool o = 1;
			for (int j = 0; j < 30; j++)
				if (cnt[j] % i) o = 0;
			if (o) printf("%d ", i);
		}
		puts("");
	}
    return 0;
}