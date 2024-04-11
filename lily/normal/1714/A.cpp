#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 55;
int n, H, M;
int h[N], m[N];
void work() {
	read(n); read(H); read(M);
	int ans = 9999;
	for (int i = 1; i<= n; i++) {
		read(h[i]); read(m[i]);
		ans = min(ans, (h[i] * 60 + m[i] - H * 60 - M + 24 * 60) % (24 * 60));
	}
	printf("%d %d\n", ans / 60, ans % 60);
}

int main() {
	int T;
	read(T);
	while (T--) work();

}