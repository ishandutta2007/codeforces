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

const LL mx = 100000000000LL;

vector<LL> lucky;

void genLucky(LL x) {
	if (x > mx) {
		return;
	}
	lucky.PB(x);
	genLucky(10 * x + 4);
	genLucky(10 * x + 7);
}

int main() {
	genLucky(0);
	sort(ALL(lucky));
	int l, r;
	scanf("%d %d", &l, &r);
	LL res = 0;
	FORE (it, lucky) {
		if (*it > 0) {
			LL cl = max(*(it - 1) + 1, (LL) l);
			LL cr = min(*it, (LL) r);
			if (cl <= cr) {
				res += (cr - cl + 1) * *it;
			}
		}
	}

	cout << res << endl;

	return 0;
}