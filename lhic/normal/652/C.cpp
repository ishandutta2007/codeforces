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

const int MAXN = 310000;

ll ans;
int n, m;
int p[MAXN];
vector<int> eds[MAXN];
int pos[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i), --p[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		pos[p[i]] = i;
	int now = 0;
	for (int i = 0; i < n; ++i) {
		for (int j: eds[p[i]])
			if (pos[j] < i)
				now = max(now, pos[j] + 1);
		ans += i - now + 1;
	}
	cout << ans << "\n";

	return 0;
}