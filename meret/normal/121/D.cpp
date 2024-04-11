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

vector<LL> lucky;

void getLucky(LL x, int dig = 0) {
	if (x > 0) {
		lucky.PB(x);
	}
	if (dig < 18) {
		getLucky(x * 10 + 4, dig + 1);
		getLucky(x * 10 + 7, dig + 1);
	}
}

int n;

LL k;

LL minLen;

vector<LL> sStarts, sEnds;

const int N = 1000005;

LL rightCost[N];
LL leftCost[N];

int main() {
	minLen = 1000000000000000000LL;
	getLucky(0);
	sort(ALL(lucky));

	ios_base::sync_with_stdio(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		LL st, en;
		cin >> st >> en;
		minLen = min(minLen, en - st + 1);
		sStarts.PB(st);
		sEnds.PB(en);
	}

	sort(ALL(sStarts));
	sort(ALL(sEnds));

	{

		LL cost = 0;

		int moving = 0;

		LL prev = 0;
		int cur = 0;
		for (int r = 0; r < (int) lucky.size(); ++r) {
			if (cost <= k) {
				if (LD(cost) + LD(moving) * LD(lucky[r] - prev) > LD(2) * (k + 100)) {
					cost = k + 1;
				} else {
					cost += moving * (lucky[r] - prev);
					while (cur < (int) sEnds.size() && sEnds[cur] < lucky[r]) {
						++moving;
						cost += lucky[r] - sEnds[cur];
						cost = min(cost, k + 1);
						++cur;
					}
					cost = min(cost, k + 1);
				}
			}
			rightCost[r] = cost;
			prev = lucky[r];
		}
	}


	{

		LL cost = 0;

		int moving = 0;

		LL prev = 0;
		int cur = (int) sStarts.size() - 1;
		for (int l = (int) lucky.size() - 1; l >= 0; --l) {
			if (cost <= k) {
				if (LD(cost) + LD(moving) * LD(prev - lucky[l]) > LD(2) * (k + 100)) {
					cost = k + 1;
				} else {
					cost += moving * (prev - lucky[l]);
					while (cur >= 0 && sStarts[cur] > lucky[l]) {
						++moving;
						cost += sStarts[cur] - lucky[l];
						cost = min(cost, k + 1);
						--cur;
					}
					cost = min(cost, k + 1);
				}
			}
			leftCost[l] = cost;
			prev = lucky[l];
		}
	}

	int l = 0;
	int result = 0;
	for (int r = 0; r < (int) lucky.size(); ++r) {
		while (l <= r && (leftCost[l] + rightCost[r] > k || (lucky[r] - lucky[l] + 1 > minLen))) {
			++l;
		}
		result = max(result, r - l + 1);
	}


	cout << result << "\n";

	return 0;
}