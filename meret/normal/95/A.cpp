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

int n;
string t[105];

string s;

string low(string s) {
	for (int i = 0; i < SIZE(s); ++i)
		s[i] = tolower(s[i]);
	return s;
}

bool change[105];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	cin >> s;
	char lucky;
	cin >> lucky;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j + SIZE(t[i]) <= SIZE(s); ++j)
			if (low(s.substr(j, t[i].size())) == low(t[i])) {
				for (int k = j; k < j + SIZE(t[i]); ++k)
					change[k] = true;
			}
	for (int i = 0; i < SIZE(s); ++i)
		if (change[i]) {
			char choice = lucky;
			if (tolower(s[i]) == tolower(lucky))
				choice = (lucky == 'a') ? 'b' : 'a';
			if (isupper(s[i])) {
				s[i] = toupper(choice);
			} else {
				s[i] = tolower(choice);
			}
		}
	cout << s << endl;
}