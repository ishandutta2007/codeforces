/* Never Say Die */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
int ch = 0;
template <class T> inline void read(T &a) {
	bool f = 0; a = 0;
	while (ch < '0' || ch > '9') {if (ch == '-') f = 1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
	if (f) a = -a;
}

#define MAXN 100005

int n;
int a[MAXN], b[MAXN];

bool cmp(int x, int y){
	return a[x] < a[y];
}

set <int> s;


int t[MAXN];

void upd(int x, int d) {
	for ( ; x <= n; x += x & -x) t[x] += d;
}

int qry(int l, int r) {
	if (l > r) {
		return qry(l, n) + qry(1, r);
	}
	int ret = 0;
	for ( l-- ; l; l -= l & -l) ret -= t[l];
	for ( 	  ; r; r -= r & -r) ret += t[r];
	return ret;
}


int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) b[i] = i, upd(i, 1);
	sort(b + 1, b + n + 1, cmp);
	int now = 1;
	LL ans = 0;
	for (int i = 1, p, j; i <= n; i = j) {
		p = a[b[i]], j = i;
		while (j <= n && a[b[j]] == p) s.insert(b[j++]);
		while (s.size()) {
			set <int>::iterator it = s.lower_bound(now);
			if (it == s.end()) it = s.begin();
			ans += qry(now, *it);
			upd(*it, -1); now = (*it) % n + 1;
			s.erase(it);
		}
	}
	printf("%lld\n", ans);
	return 0;
}