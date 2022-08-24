#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

set<pair<int, int> > ssu;
set<pair<int, int> > ssl;
set<int> aa;
int n, q;

int main() {
	ssu.insert(make_pair(0, 0));
	ssl.insert(make_pair(0, 0));
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		char c;
		scanf(" %c", &c);
		if (aa.count(y)) {
			printf("0\n");
			continue;
		}
		aa.insert(y);
		if (c == 'U') {
			auto it = ssl.lower_bound(make_pair(y + 1, 0));
			--it;
			auto it2 = ssu.lower_bound(make_pair(x, 0)); 
			int ans;
			if (it2 == ssu.end() || it->first > n + 1 - it2->first)
				ans = it->first;
			else
				ans = it2->second;
			printf("%d\n", y - ans);
			
			ssu.insert(make_pair(x, ans));
		}
		else {
			auto it = ssu.lower_bound(make_pair(x + 1, 0));
			--it;
			auto it2 = ssl.lower_bound(make_pair(y, 0)); 
			int ans;
			if (it2 == ssl.end() || it->first > n + 1 - it2->first)
				ans = it->first;
			else
				ans = it2->second;
			printf("%d\n", x - ans);
			ssl.insert(make_pair(y, ans));
		}
	}
	return 0;
}