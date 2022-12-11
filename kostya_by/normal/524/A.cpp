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

const int MAXN = 222;

int n = 0;
map<int, int> cid;
int rcid[MAXN];
int graph[MAXN][MAXN];
vector<int> answer[MAXN];

int get_id(int id) {
	if (cid.find(id) == cid.end()) {
		cid[id] = ++n;
		rcid[n] = id;
	}
	return cid[id];
}

void solve() {
	int m, k; cin >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a = get_id(a);
		b = get_id(b);
		graph[a][b] = graph[b][a] = 1;
	}
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++) {
			if (x == y || graph[x][y]) {
				continue;
			}
			int a = 0, b = 0;
			for (int z = 1; z <= n; z++) {
				if (graph[x][z]) {
					b += 1;
					if (graph[y][z]) {
						a += 1;
					}
				}
			}
			// cerr << rcid[x] << " " << rcid[y] << " " << a << " " << b << " " << k << "\n"; 
			if (a * 100 >= k * b) {
				answer[x].push_back(rcid[y]);
			}
		}
	for (auto p : cid) {
		int id = p.first;
		int pos = p.second;
		cout << id << ": " << answer[pos].size() << " ";
		sort(answer[pos].begin(), answer[pos].end());
		for (int a : answer[pos]) {
			cout << a << " "; 
		}
		cout << "\n";
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}