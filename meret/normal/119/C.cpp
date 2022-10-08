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

typedef long long LL;

LL mn[55], mx[55];
int complexity[55];

LL best[55][55][105];
pair<int, int> prev[55][55][105];

int n, m, k;

int main() {

	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++i) {
		cin >> mn[i] >> mx[i] >> complexity[i];
	}

	memset(best, -1, sizeof(best));

	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= mx[i] - mn[i]; ++j) {
			best[1][i][j] = mn[i] + j;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int last = 1; last <= m; ++last) {
			for (int used = 0; used <= mx[last] - mn[last]; ++used) {
				if (best[i][last][used] != -1) {
					for (int nx = 1; nx <= m; ++nx) {
						if (complexity[nx] > complexity[last]) {
							vector<LL> choices;
							choices.PB((mn[last] + used) + k);
							choices.PB((mn[last] + used) * k);
							FORE (it, choices) {
								if (mn[nx] <= *it && *it <= mx[nx]) {
									int df = *it - mn[nx];
									if (best[i + 1][nx][df] < best[i][last][used] + *it) {
										best[i + 1][nx][df] = best[i][last][used] + *it;
										prev[i + 1][nx][df] = MP(last, used);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	LL res = -1;
	for (int last = 1; last <= m; ++last) {
		for (int used = 0; used <= mx[last] - mn[last]; ++used) {
			res = max(res, best[n][last][used]);
		}
	}

	if (res < 0) {
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	for (int last = 1; last <= m; ++last) {
		for (int used = 0; used <= mx[last] - mn[last]; ++used) {
			if (res == best[n][last][used]) {
				vector<pair<int, LL> > v;
				while (n > 0) {
					v.PB(MP(last, mn[last] + used));
					PII prv = prev[n][last][used];
					last = prv.ST;
					used = prv.ND;
					--n;
				}
				reverse(ALL(v));
				FORE (it, v) {
					cout << it->ST << " " << it->ND << endl;
				}
				return 0;
			}
		}
	}

	return 0;
}