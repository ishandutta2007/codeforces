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
const int MAXN = 400000;

int en[MAXN];
vector<int> vv[MAXN];
int ans = 0;
int cnt = 0;
int now = 0;
int n,q;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		int x;
		scanf("%d", &x);
		if (t == 1) {
			vv[x].push_back(cnt);
			++cnt;
			++ans;
		}
		else if (t == 2) {
			for (int j: vv[x])
				if (!en[j])
					--ans, en[j] = 1;
			vv[x].clear();
		}
		else {
			while (now < x) {
				if (!en[now])
					--ans, en[now] = 1;
				++now;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}