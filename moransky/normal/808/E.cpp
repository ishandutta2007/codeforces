#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 100005, M = 300005;
int n, m, tot[4], w[4][N];
LL ans = 0;
struct S{
	LL v, a, b, c;
}f[M]; 
void inline upd(S &x, S y) {
	if(y.v > x.v) x = y;
} 

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1, b, c; i <= n; i++) {
		scanf("%d%d", &b, &c);
		w[b][++tot[b]] = c;
	}
	for(int i = 1; i <= 3; i++) {
		sort(w[i] + 1, w[i] + 1 + tot[i]);
		reverse(w[i] + 1, w[i] + 1 + tot[i]);
	} 
	for(int i = 0; i <= m; i++) {
		LL v = f[i].v, a = f[i].a, b = f[i].b, c = f[i].c;
		LL vA = w[1][a + 1], vB = w[2][b + 1], vC = w[3][c + 1];
		ans = max(ans, v);
		if(i + 1 <= m && a < tot[1]) upd(f[i + 1], (S){ v + vA, a + 1, b, c });
		if(i + 2 <= m && b < tot[2]) upd(f[i + 2], (S){ v + vB, a, b + 1, c });
		if(i + 3 <= m && c < tot[3]) upd(f[i + 3], (S){ v + vC, a, b, c + 1 });
		if(i + 2 <= m && a && c < tot[3]) upd(f[i + 2], (S){ v - w[1][a] + vC, a - 1, b, c + 1 });
	}
	printf("%lld\n", ans);
    return 0;
}