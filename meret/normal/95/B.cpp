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

int main() {
	string s;
	cin >> s;
	int n = SIZE(s);
	int last = -1;
	int c4 = 0;
	int c7 = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n; ++i) {
			if (s[i] > '7')
				break;
			int rem = n - i;
			if (s[i] < '4') {
				if (abs(c7 - c4) <= rem)
					last = i;
				break;
			} else if (s[i] == '4') {
				if (abs(c7 + 1 - c4) <= rem - 1)
					last = i;
				++c4;
			} else if (s[i] < '7') {
				if (abs(c7 + 1 - c4) <= rem - 1)
					last = i;
				break;
			} else if (s[i] == '7') {
				++c7;
			} else {
				break;
			}
		}
		if (c4 + c7 == n && c4 == c7) {
			cout << s << endl;
			return 0;
		}
	}
	if (last == -1) {
		n += 2 - (n % 2);
		for (int i = 0; i < n / 2; ++i)
			printf("4");
		for (int i = 0; i < n / 2; ++i)
			printf("7");
		printf("\n");
		return 0;
	} else {
		c4 = c7 = 0;
		for (int i = 0; i < last; ++i) {
			if (s[i] == '4')
				++c4;
			else if (s[i] == '7')
				++c7;
			putchar(s[i]);
		}
		if (s[last] < '4' && abs(c4 + 1 - c7) <= n - last - 1) {
			putchar('4');
			++c4;
		} else {
			putchar('7');
			++c7;
		}
		while (c4 < n / 2) {
			putchar('4');
			++c4;
		}
		while (c7 < n / 2) {
			putchar('7');
			++c7;
		}
		putchar('\n');
	}
}