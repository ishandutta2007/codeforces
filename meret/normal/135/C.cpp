#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 100005;

char s[N];

int main() {
	scanf("%s", s);
	int c0 = 0, c1 = 0, ca = 0;
	int i;
	for (i = 0; s[i]; ++i) {
		if (s[i] == '0') {
			++c0;
		} else if (s[i] == '1') {
			++c1;
		} else {
			++ca;
		}
	}
	char last = s[i - 1];
	if (c0 + ca > c1) {
		printf("00\n");
	}
	if (last == '1' && (c1 + ca >= c0 && c0 + ca >= c1 - 1)) {
		printf("01\n");
	} else if (last == '?' && (c1 + ca >= c0 && c0 + ca - 1 >= c1)) {
		printf("01\n");
	}
	if (last == '0' && (c1 + ca >= c0 && c0 + ca >= c1 - 1)) {
		printf("10\n");
	} else if (last == '?' && (c1 + ca - 1 >= c0 + 1 && c0 + ca >= c1 - 1)) {
		printf("10\n");
	}
	if (c1 + ca > c0 + 1) {
		printf("11\n");
	}
}