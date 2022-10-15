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

vector <pii> a;
int cnt[2000005], last[2000005];

int n, K, tot = 1;

int main() {
	read(n); read(K);
	/*if (K == 2) {
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i++) printf("%d %d\n", i, i + 1);
		return 0;
	}*/
	for (int i = 2; i <= K + 1; i++) a.push_back(mp(1, i)), last[i] = i, cnt[i] = 1;
	for (int j = K + 2; j <= n; j++) {
		a.push_back(mp(last[2 + j % K], j));
		cnt[2 + j % K]++;
		last[2 + j % K] = j;
	}
	sort(cnt + 2, cnt + K + 2);
	printf("%d\n", cnt[K + 1] + cnt[K]);
	for (int i = 0; i < n - 1; i++) {
		printf("%d %d\n", a[i].fir, a[i].sec);
	}
	return 0;
}