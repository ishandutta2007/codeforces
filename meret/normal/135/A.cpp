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

int main() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	sort(ALL(v));
	int last = 1;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1 && v[i] == 1) {
			last = 2;
		}
		printf("%d", last);
		last = v[i];
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}