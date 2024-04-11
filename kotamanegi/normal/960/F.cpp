#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007 
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
set<pair<int, int>> vertexs[200000];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		vertexs[i].insert(make_pair(-1, 0));
	}
	REP(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		auto hoge = vertexs[a].lower_bound(make_pair(c + 1, -1));
		hoge--;
		int coo = hoge->second + 1;
		hoge = vertexs[b].lower_bound(make_pair(c + 1, -1));
		hoge--;
		if (coo > hoge->second) {
			vertexs[b].insert(make_pair(c, coo));
			hoge = vertexs[b].lower_bound(make_pair(c + 1, -1));
			while (hoge != vertexs[b].end()) {
				if (hoge->second <= coo) {
					auto bobo = hoge;
					bobo++;
					vertexs[b].erase(hoge);
					hoge = bobo;
				}
				else break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		auto hoge = vertexs[i].end();
		hoge--;
		ans = max(ans, hoge->second);
	}
	cout << ans << endl;
	return 0;
}