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

map<string, vector<int> > places;
map<string, int> scores;

vector< pair<pair<int, vector<int> >, string> > sort1;
vector< pair<pair<int, pair<int, vector<int> > >, string> > sort2;

int awards[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main() {
	int races;
	cin >> races;
	for (int i = 1; i <= races; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			string driver;
			cin >> driver;
			if (j < 10)
				scores[driver] += awards[j];
			if (places.find(driver) == places.end())
				places[driver] = vector<int> (50, 0);
			++places[driver][j];
		}
	}
	FOREACH (driver, scores) {
		string name = driver->ST;
		sort1.PB(MP(MP(scores[name], places[name]), name));
		sort2.PB(MP(MP(places[name][0], MP(scores[name], places[name])), name));
	}
	sort(ALL(sort1));
	sort(ALL(sort2));
	reverse(ALL(sort1));
	reverse(ALL(sort2));
	cout << sort1[0].ND << endl;
	cout << sort2[0].ND << endl;
}