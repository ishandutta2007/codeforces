#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define mp(a, b) make_pair
#define x first
#define y second
#define read(x) scanf("%d", &x)
#define readl(x) scanf("%lld", &x)
#define readd(x) scanf("%lf", &x)

struct node {
	int a, b, c, d;
};
vector <node> ans; 
const int N = 1231;
int n;
int a[N], b[N], ra[N], rb[N];

int c[N], d[N], rc[N], rd[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), ra[a[i]] = i;
	for (int i = 1; i <= n; i++) read(b[i]), rb[b[i]] = i;

	for (int i = 1; i <= n; i++) c[i] = d[i] = rc[i] = rd[i] = i;
	
	// A, B :  i 
	// C, D : i 
	for (int i = 1; i <= n; i++) {
		if (c[i] == ra[i] && d[i] == rb[i]) continue;
		ans.push_back({rc[ra[i]], i, i, rd[rb[i]]});
		int p = c[i], q = d[i];
		swap(c[i], c[rc[ra[i]]]);
		swap(d[i], d[rd[rb[i]]]);
		swap(rc[p], rc[ra[i]]);
		swap(rd[q], rd[rb[i]]);
	}
	


	cout << ans.size() << endl;
	for (auto v : ans) {
		printf("%d %d %d %d\n", v.a, v.b, v.c, v.d);
	}
}