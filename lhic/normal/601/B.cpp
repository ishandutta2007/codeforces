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

int n, q;
int a[120000];
int gl[120000];
int gr[120000];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; ++i)
		a[i] = abs(a[i + 1] - a[i]);
	--n;
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		while (!st.empty() && a[st.back()] < a[i])
			gr[st.back()] = i, st.pop_back();
		st.push_back(i);
	}
	for (int i = 0; i < (int)st.size(); ++i)
		gr[st[i]] = n;
	st.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && a[st.back()] <= a[i])
			gl[st.back()] = i, st.pop_back();
		st.push_back(i);
	}
	for (int i = 0; i < (int)st.size(); ++i)
		gl[st[i]] = -1;

	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		ll sum = 0;
		for (int i = l; i < r; ++i)
			sum += (ll)a[i] * (ll)(min(gr[i], r) - i) * (i - max(l - 1, gl[i]));
		cout << sum << "\n";
	}
	return 0;
}