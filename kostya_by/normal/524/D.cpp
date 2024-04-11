#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 20020;
const int MAXT = 86400;

int n, m, t;
int x[MAXN];
int color[MAXN];
vector<int> ids[MAXT];

void solve() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		x[i] = h * 60 * 60 + m * 60 + s;
		ids[ x[i] ].push_back(i);
	}
	multiset< pair<int, int> > s;
	bool is_record = false;
	int current_color = 0;
	for (int i = 0; i < MAXT; i++) {

		while (true) {
			if (s.size() == 0) {
				break;
			}
			int x = s.begin()->first;
			if (x + t - 1 < i) {
				s.erase( s.begin() );
				continue;
			} else {
				break;
			}
		}

		for (int j = 0; j < ids[i].size(); j++) {
			int id = ids[i][j];
			if (s.size() < m) {
				++current_color;
				color[id] = current_color;
				s.insert( make_pair(i, color[id]) );
				if (s.size() == m) {
					is_record = true;
				}
			} else {
				auto it = s.end(); --it;
				// auto it = s.begin();
				color[id] = it->second;
				s.erase(it);
				s.insert( make_pair(i, color[id]) );
			}
		}

	}
	if (is_record) {
		printf("%d\n", current_color);
		for (int i = 0; i < n; i++) {
			printf("%d\n", color[i]);
		}
	} else {
		printf("No solution\n");
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}