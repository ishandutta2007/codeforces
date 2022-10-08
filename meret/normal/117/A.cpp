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

int n, m;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		int st, en, time;
		scanf("%d %d %d", &st, &en, &time);
		--st;
		--en;
		if (st == en) {
			printf("%d\n", time);
			continue;
		}
		vector<int> getOn, getOff;
		getOn.PB(st);
		if (st > 0 && st < m - 1) {
			getOn.PB(m + m - st - 2);
		}
		getOff.PB(en);
		if (en > 0 && en < m - 1) {
			getOff.PB(m + m - en - 2);
		}
		int len = 2 * (m - 1);
		int start = time % len;
		int res = (int) 1e9;
		FORE (on, getOn) {
			FORE (off, getOff) {
				int dist = (*off - *on + len) % len;
				dist += (*on - start + len) % len;
				res = min(res, dist);
			}
		}
		printf("%d\n", time + res);
	}

    return 0;
}