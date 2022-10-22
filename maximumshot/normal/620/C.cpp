#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int n;

	scanf("%d", &n);

	vec< int > a(n), crd;

	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		crd.push_back(a[i]);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());

	for(int i = 0;i < n;i++) a[i] = lower_bound(ALL(crd), a[i]) - crd.begin();

	int mx = *max_element(ALL(a));

	if(mx == n - 1) {
		cout << -1 << '\n';
		return true;
	}

	vec< int > pos(mx + 1, -inf);

	vec< pii > ans;

	int last = -1, tmax = -inf;

	for(int i = 0;i < n;i++) {
		// [last + 1 .. i]
		tmax = max(tmax, pos[a[i]]);
		if(tmax > last) ans.push_back(mp(last + 1, i)), last = i;
		pos[a[i]] = i;
	}

	ans[(int)ans.size() - 1].second = n - 1;

	cout << (int)ans.size() << '\n';

	for(auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}