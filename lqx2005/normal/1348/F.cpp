#include<bits/stdc++.h>

using namespace std;
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
int n;
int a[N], b[N], id[N], c[N], r[N];
int lab[N];
multiset<par> S;
int cmp(int x, int y) { return a[x] < a[y]; }
int ocmp(int x, int y) { return b[x] < b[y]; }
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		id[i] = lab[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	sort(lab + 1, lab + n + 1, ocmp);
	int now = 0;
	for(int i = 1; i <= n; i++) {
		while(now + 1 <= n && a[id[now + 1]] <= i) now++, S.insert(mp(b[id[now]], id[now]));
		int u = S.begin() -> y;
		c[u] = i, r[i] = u;
		S.erase(S.begin());
	}
	int n1 = 0, n2 = 0;
	for(int i = 1; i <= n; i++) {
		while(n1 + 1 <= n && a[id[n1 + 1]] <= i) n1++, S.insert(mp(c[id[n1]], id[n1]));
		S.erase(S.find(mp(c[r[i]], r[i])));
		multiset<par>::iterator it = S.lower_bound(mp(a[r[i]], 0));
		if(it != S.end() && it -> x <= b[r[i]]) {
			int u = it -> y;
			printf("NO\n");
			for(int i = 1; i <= n; i++) printf("%d%c" , c[i], " \n" [i == n]);
			swap(c[r[i]], c[u]);
			for(int i = 1; i <= n; i++) printf("%d%c" , c[i], " \n" [i == n]);
			return 0;
		}
		S.insert(mp(c[r[i]], r[i]));
		while(n2 + 1 <= n && b[lab[n2 + 1]] <= i) n2++, S.erase(S.find(mp(c[lab[n2]], lab[n2])));
	}
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%d%c" , c[i], " \n" [i == n]);
	return 0;
}