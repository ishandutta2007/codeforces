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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.first != b.first) ? (a.first > b.first) : (a.second > b.second);
}

int mxa, mxb;

int n, p, q;

ld ans;

vector<pair<int, int> > vv;
vector<pair<int, int> > vv2;

int cmm(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	b.first -= a.first;
	b.second -= a.second;
	c.first -= a.first;
	c.second -= a.second;
	if ((ll)b.first * (ll)c.second - (ll)b.second * (ll)c.first <= 0)
		return 1;
	else
		return 0;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		vv.push_back(make_pair(a, b));
		mxa = max(a, mxa);
		mxb = max(b, mxb);
	}
	ans = p + q;
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < (int)vv.size(); ++i) {
		if (!vv2.empty()) {
			if (vv2.back().second >= vv[i].second)
				continue;
			while ((int)vv2.size() >= 2 && cmm(vv2[vv2.size() - 2], vv2[vv2.size() - 1], vv[i]))
				vv2.pop_back();
			vv2.push_back(vv[i]);
		}
		else {
			vv2.push_back(vv[i]);
		}
	}
	vv.clear();

	vv.push_back(make_pair(mxa, 0));
	for (int i = 0; i < (int)vv2.size(); ++i)
		vv.push_back(vv2[i]);
	vv.push_back(make_pair(0, mxb));
	vv2 = vv;
	
	for (int i = 0; i < (int)vv2.size() - 1; ++i) {
		pair<int, int> a, b;
		a = vv2[i];
		b = vv2[i + 1];
		if ((ll)a.first * q < (ll)p * a.second)
			continue;
		if ((ll)b.first * q > (ll)p * b.second)
			continue;
		ld lam = ((ld)b.first * q - (ld)b.second * p) / ((ld)b.first * q - (ld)b.second * p - q * (ld)a.first + p * (ld)a.second);
		ld gx = a.first * lam + b.first * (1 - lam);
		ans = min(ans, p / gx);
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";
	return 0;
}