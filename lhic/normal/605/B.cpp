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

int n, m;

vector<tuple<int, int, int> > ed;

set<pair<int, int> > usl;

int goa[120000];
int gob[120000];
const int MAX = 150000;


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int c, e;
		scanf("%d%d", &c, &e);
		e ^= 1;
		ed.push_back(make_tuple(c, e, i));
	}
	sort(ed.begin(), ed.end());
	int cc = 1;
	for (int i = 0; i < (int)ed.size(); ++i) {
		int c, e, x;
		tie(c, e, x) = ed[i];
		e ^= 1;
		if (e == 0) {
			if (usl.empty()) {
				cout << -1 << "\n";
				return 0;
			}
			goa[x] = usl.begin()->first;
			gob[x] = usl.begin()->second;
			usl.erase(usl.begin());
		}
		else {
			goa[x] = 0;
			gob[x] = cc;
			for (int j = 1; j < cc && (int)usl.size() < MAX; ++j)
				usl.insert(make_pair(j, cc));	
			++cc;
		}
	}
	for (int i = 0; i < m; ++i)
		printf("%d %d\n", goa[i] + 1, gob[i] + 1);

	return 0;
}