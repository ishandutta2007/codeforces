#include<bits/stdc++.h>
#define oo 0x3f3f3f3f
#define cl(x) memset(x, 0, sizeof(x))
#define maxn 1000010
#define mo 1000000007
#define maxm 110
#define debug(x) cerr<<#x<<" = "<<x<<endl
typedef long long ll;

using namespace std;
void gn(int &x) {
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
}
int n, L, m, a[maxn], b[maxn], c[maxn];
struct node {
	int x[maxm];
	void clear() {cl(x);}
}A, B, C;
void add(int &a, int b) {
	a += b; a %= mo;
}
node operator * (const node &a, const node &b) {
	node c; c.clear();
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			add(c.x[(i + j) % m], 1ll * a.x[i] * b.x[j] % mo);
	return c;
}
node operator ^ (node a, int b) {
	node c; c.clear(); c.x[0] = 1;
	for (; b; b >>= 1, a = a * a) {
		if (b & 1) c = c * a;
	}
	return c;
}
int main() {
	gn(n); gn(L); gn(m);
	for (int i = 1; i <= n; ++i) gn(a[i]), a[i] %= m, ++A.x[a[i]];
	for (int i = 1; i <= n; ++i) gn(b[i]), b[i] %= m, ++B.x[b[i]];
	for (int i = 1; i <= n; ++i) gn(c[i]), c[i] += b[i], c[i] %= m, ++C.x[c[i]];
	B = B ^ (L - 2);
	A = A * B * C;
	printf("%d\n", A.x[0]);
	return 0;
}