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

int n;
int a[100005], b[100005];

bool ck(int m) {
	for (int i = 1; i + m <= n; i++) if (a[i] == a[i + m]) return 0;
	return 1;
}


int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1,a + n + 1);
	int l = 1, r = n ;
	while (l < r) {
		int mid = (l  + r) >> 1;
		if (ck(mid)) r = mid;
		else l = mid + 1;
	}	
	cout << n - l;

	return 0;
}