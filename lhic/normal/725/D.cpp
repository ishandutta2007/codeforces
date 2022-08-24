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

const int MAXN = 400000;
multiset<ll> ss;
int n;
ll t[MAXN];
ll w[MAXN];
vector<pair<ll, ll> > vv;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", t + i, w + i);
	}
	for (int i = 1; i < n; ++i) {
		vv.push_back(make_pair(t[i], w[i]));
	}
	sort(vv.begin(), vv.end());
	ll cur = t[0];
	while (!vv.empty() && vv.back().first > cur) {
		ss.insert(vv.back().second - vv.back().first + 1);
		vv.pop_back();
	}
	int bst = ss.size() + 1;
	while (true) {
		if (!ss.empty() && *ss.begin() <= cur) {
			cur -= *ss.begin();
			ss.erase(ss.begin());
			while (!vv.empty() && vv.back().first > cur) {
				ss.insert(vv.back().second - vv.back().first + 1);
				vv.pop_back();
			}
		}
		else {
			break;
		}
		bst = min(bst, (int)ss.size() + 1);
	}
	cout << bst << "\n";
	return 0;
}