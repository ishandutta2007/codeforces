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

#define MAXN 1000005

int n, p[MAXN], cnt[MAXN];

vector <int> G[MAXN];

LL tot = 0, ans;
int tag;

int main() {
	read(n);
	
	int d = 0;

	for (int i = 1; i <= n; i++) {
		read(p[i]);
		tot += abs(p[i] - i);
		if (p[i] > i) {
			d--;
			cnt[p[i] - i]++;
		}
		else {
			d++;
			cnt[n - i + p[i]]++;
		}
	}
	ans = tot; tag = 0;

	for (int t = 1, j = n; t < n; t++, j--) {
		tot -= (n - p[j]);
		tot += p[j] - 1;
		d--; tot += d; d--;
		d += cnt[t] * 2;
		if (ans > tot) ans = tot, tag = t;
	}
	printf("%lld %d\n", ans, tag);
	return 0;
}