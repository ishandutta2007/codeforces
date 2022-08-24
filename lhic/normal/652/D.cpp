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

const int MAXN = 420000;

int n;
vector<pair<int, int> > vv;
vector<int> go;
int ans[MAXN];
int f[MAXN];
int op[MAXN];
int rr[MAXN];

void upd(int x) {
	x = lower_bound(go.begin(), go.end(), x) - go.begin();
	for (; x < (int)go.size(); x |= (x + 1))
		++f[x];
}

int get(int x) {
	x = lower_bound(go.begin(), go.end(), x) - go.begin();
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += f[x];
	return ans;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		vv.push_back(make_pair(l, i));
		vv.push_back(make_pair(r, i));
		go.push_back(r);
	}
	sort(vv.begin(), vv.end());
	sort(go.begin(), go.end());
	for (int i = (int)vv.size() - 1; i >= 0; --i) {
		if (op[vv[i].second]) {
			ans[vv[i].second] = get(rr[vv[i].second]);
			upd(rr[vv[i].second]);
		}
		else {
			op[vv[i].second] = 1;
			rr[vv[i].second] = vv[i].first;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}