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
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int S = 400;

vector<pair<int, LL*> > queries[S + 5];

int t[300005];

LL result[300005];
LL dp[300005];
int n;

void answerQueries(int s) {
	if (queries[s].empty())
		return;
	sort(ALL(queries[s]));
	for (int i = n; i >= 1; --i) {
		if (i + s > n)
			dp[i] = t[i];
		else
			dp[i] = t[i] + dp[i + s];
		while (!queries[s].empty() && queries[s].back().ST == i) {
			*queries[s].back().ND = dp[i];
			queries[s].pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> t[i];
	int p;
	cin >> p;
	for (int i = 1; i <= p; ++i) {
		int a, b;
		cin >> a >> b;
		if (b <= S)
			queries[b].PB(MP(a, &result[i]));
		else {
			result[i] = 0;
			for (int j = a; j <= n; j += b)
				result[i] += t[j];
		}
	}
	for (int i = 1; i <= S; ++i)
		answerQueries(i);
	for (int i = 1; i <= p; ++i)
		cout << result[i] << "\n";
}