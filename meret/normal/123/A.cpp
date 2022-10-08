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

bool freePos[1005];

int cnt[256];

int main() {
	string s;
	cin >> s;
	FOREACH (it, s) {
		++cnt[*it];
	}
	freePos[1] = true;
	for (int i = s.size() / 2 + 1; i <= (int) s.size(); ++i) {
		bool prime = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			freePos[i] = true;
		}
	}
	char mx = 'a';
	for (int i = 'a'; i <= 'z'; ++i) {
		if (cnt[i] > cnt[mx]) {
			mx = i;
		}
	}
	string oth;
	for (int i = 'a'; i <= 'z'; ++i) {
		if (i != mx) {
			for (int j = 0; j < cnt[i]; ++j) {
				oth += char(i);
			}
		}
	}
	string res = "";
	for (int i = 1; i <= (int) s.size(); ++i) {
		if (freePos[i]) {
			if (!oth.empty()) {
				res += oth[0];
				oth.erase(0, 1);
			} else {
				res += mx;
				--cnt[mx];
			}
		} else {
			if (cnt[mx] == 0) {
				cout << "NO" << endl;
				return 0;
			} else {
				res += mx;
				--cnt[mx];
			}
		}
	}
	cout << "YES" << endl;
	cout << res << endl;
}