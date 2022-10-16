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
 
int inline ask(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int x; read(x);
	return x;
}
 
int L = 1e9; 
 
int main() {
	int A = ask(1, 1), B = ask(1, L), C = ask(L, 1), D = ask(L, L);
	int s = A + 2;
	int yq = A - B + L + 1;
	int xp = A - C + L + 1;
	int l = 1, r = L - 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		int o = ask(mid, 1);
		if (o == A - (mid - 1)) l = mid;
		else r = mid - 1;
	}
	int x = r;
	int y = s - x;
	int p = xp - x;
	int q = yq - y;
	printf("! %d %d %d %d\n", x, y, p, q); 
	fflush(stdout);
    return 0;
}