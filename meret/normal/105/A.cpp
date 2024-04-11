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

map<string, int> level;

int main() {
	int old, next;
	int z;
	char dot;
	int k;
	cin >> old >> next >> z >> dot >> k;
	for (int i = 0; i < old; ++i) {
		string name;
		int lev;
		cin >> name >> lev;
		if ((lev * k) / 100 >= 100)
			level[name] = (lev * k) / 100;
	}
	for (int i = 0; i < next; ++i) {
		string name;
		cin >> name;
		if (level.find(name) == level.end())
			level[name] = 0;
	}
	cout << level.size() << endl;
	FOREACH (it, level) {
		cout << it->first << " " << it->second << endl;
	}
}