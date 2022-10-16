#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200005;
typedef long long LL;
int n, a[N], tot = 0;
LL c[N];
LL sum[N];
LL ans = 0;
struct Op{
	int l, r, x, id;
	bool operator < (const Op &x) const {
		return r < x.r;
	}
}e[N];
void inline add(int x, int k) {
	for (; x <= n; x += x & -x) c[x] += k;
}
LL inline ask(int x) {
	LL res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), a[i] = min(a[i], n);
	
	for (int i = 1; i < n; i++) {
		if(i + 1 > a[i]) continue; 
		++tot;
		e[tot] = (Op) { i + 1, a[i], i, tot };
		//cout << e[tot].l << " " << e[tot].r << " " << e[tot].x << endl;
	}
	
	int j = n + 1;
	for (int i = tot; i; i--) {
		while(j > e[i].l) {
			--j; add(a[j], 1);
		}
		sum[i] = ask(n) - ask(e[i].x - 1);
	}
	memset(c, 0, sizeof c);
	sort(e + 1, e + 1 + tot);
	j = n + 1;
	for (int i = tot; i; i--) {
		while(j > e[i].r + 1) {
			--j; add(a[j], 1);
		}
		sum[e[i].id] -= ask(n) - ask(e[i].x - 1);
		ans += sum[e[i].id]; 
	}
	printf("%lld\n", ans);
	return 0;
}