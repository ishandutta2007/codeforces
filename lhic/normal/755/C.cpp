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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;
int n;

int was[MAXN];
vector<int> eds[MAXN];

void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		eds[i].push_back(x);
		eds[x].push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (!was[i]) {
			dfs1(i);
			++cnt;
		}
	cout << cnt << "\n";
	return 0;
}