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

const int N = 100005;

int n;

int t[N];
int initial[N];

vector<int> positions[N];
vector<vector<int> > lcp[N];

int shortestRepeat[N];

map<int, int> scale;

int alphabetSize;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		initial[i] = t[i];
		if (scale.find(t[i]) == scale.end())
			scale[t[i]] = ++alphabetSize;
		t[i] = scale[t[i]];
	}
	vector<PII> repeats;
	for (int i = n; i >= 1; --i) {
		shortestRepeat[i] = 0;
		if (i == n) {
			lcp[t[i]].push_back(vector<int> ());
			positions[t[i]].push_back(i);
		} else {
			int nx = positions[t[i + 1]].size() - 1;
			int curIndex = positions[t[i]].size();
			lcp[t[i]].push_back(vector<int> (positions[t[i]].size(), 1));
			for (int j = 0; j < positions[t[i]].size(); ++j) {
				int nextPos = positions[t[i]][j];
				if (nextPos != n && t[i + 1] == t[nextPos + 1]) {
					int nx2 = 0;
					while (positions[t[nextPos + 1]][nx2] != nextPos + 1)
						++nx2;
					lcp[t[i]][curIndex][j] += lcp[t[i + 1]][nx][nx2];
				}
				if (lcp[t[i]][curIndex][j] >= nextPos - i)
					shortestRepeat[i] = nextPos - i;
			}
			positions[t[i]].push_back(i);
		}
		if (shortestRepeat[i])
			repeats.push_back(MP(shortestRepeat[i], i));
	}
	sort(ALL(repeats));
	int left = 1;
	for (int i = 0; i < repeats.size(); ++i) {
		if (left <= repeats[i].ND)
			left = repeats[i].ND + repeats[i].ST;
	}
	printf("%d\n", n - left + 1);
	for (int i = left; i <= n; ++i) {
		printf("%d", initial[i]);
		if (i < n)
			printf(" ");
	}
	printf("\n");
}