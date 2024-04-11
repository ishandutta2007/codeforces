#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 300005, L = 1000001;
int n, m, a[N], d[L], f[N];
LL c[N];
bool st[N];
void inline add(int x, LL k) {
	for (; x <= n; x += x & -x) c[x] += k;
}
LL inline ask(int x) {
	LL res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}
int get(int x) {
	return x == f[x] ? x : f[x] = get(f[x]);
}
int main(){
	for (int i = 1; i < L; i++)
		for (int j = i; j < L; j += i) d[j]++;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[i] = i, add(i, a[i]);
	f[n + 1] = n + 1;
	for (int i = 1, c, l, r; i <= m; i++) {
		scanf("%d%d%d", &c, &l, &r);
		if(c == 1) {
			for (int j = l; j <= r; ) {
				LL v = d[a[j]];
				add(j, - a[j] + v);
				a[j] = v;
				if(v <= 2) f[j] = j + 1;
				if(j == get(j)) j++;
				else j = f[j];
			}
		} else printf("%lld\n", ask(r) - ask(l - 1));
	}
	return 0;
}