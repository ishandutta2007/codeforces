// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 16;

int n;
LL a[N];
 
int main() {
	int T; read(T);
	while (T--){
		read(n);
		LL w = 1;
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			while (a[i] % 2 == 0) a[i] /= 2, w *= 2;
		}
		sort(a + 1, a + 1 + n);
		a[n] *= w;
		LL s = 0;
		for (int i = 1; i <= n; i++) s += a[i];
		printf("%lld\n", s);
	}
    return 0;
}