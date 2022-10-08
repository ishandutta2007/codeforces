//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

const int N = 1000005;

void findPref(char* s, int* pref) {
	int n = strlen(s);
	pref[0] = 0;
	int r = 0;
	for (int i = 1; i < n; ++i) {
		if (r + pref[r] > i) {
			pref[i] = min(pref[i - r], r + pref[r] - i);
		} else {
			pref[i] = 0;
		}
		while (s[i + pref[i]] == s[pref[i]]) {
			++pref[i];
		}
		if (i + pref[i] > r + pref[r]) {
			r = i;
		}
	}
}

void findSuf(char* s, int* suf) {
	int n = strlen(s);
	suf[0] = 0;
	for (int i = 1; i < n; ++i) {
		suf[i] = suf[i - 1];
		while (suf[i] != 0 && s[i] != s[suf[i]]) {
			suf[i] = suf[suf[i] - 1];
		}
		if (s[i] == s[suf[i]]) {
			++suf[i];
		}
	}
}

int ri = -1, rj = -1;

char a[N], b[N];

int n;

char buf[2 * N];

int pref[2 * N], suf[2 * N];

int main() {
	gets(a);
	gets(b);

	n = strlen(a);
	if (n != (int) strlen(b)) {
		printf("-1 -1\n");
		return 0;
	}

	reverse(a, a + n);

	memcpy(buf, a, n);
	buf[n] = 1;
	memcpy(buf + n + 1, b, n);

	buf[2 * n + 1] = 0;

	findSuf(buf, suf);

	reverse(a, a + n);

	memcpy(buf, b, n);
	buf[n] = 1;
	memcpy(buf + n + 1, a, n);

	buf[2 * n + 1] = 0;

	findPref(buf, pref);

	reverse(b, b + n);

	for (int i = 1; i <= n - 1; ++i) {
		if (i > 0 && a[i - 1] != b[i - 1]) {
			break;
		}
		int matchLeft = suf[2 * n - i];
		int matchRight = pref[n + 1 + i];
		if (matchLeft > 0 && matchLeft + matchRight + i >= n) {
			if (ri < i - 1) {
				ri = i - 1;
				rj = n - matchLeft;
			} else if (ri == i - 1) {
				rj = min(rj, n - matchLeft);
			}
		}
	}

	printf("%d %d\n", ri, rj);

    return 0;
}