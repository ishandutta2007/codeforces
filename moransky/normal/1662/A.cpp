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

int w[11];

int main() {
	int T; read(T);
	while (T--) {
		memset(w, 0, sizeof w);
		int n; read(n);
		while (n--) {
			int b, d; read(b), read(d);
			chkMax(w[d], b);
		}
		bool o = 0;
		int s = 0;
		for (int i = 1; i <= 10; i++)
			if (!w[i]) o = 1;
			else s += w[i];
		if (o) puts("MOREPROBLEMS");
		else printf("%d\n", s);
	}    
    return 0;
}