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

int us[300];
vector<int> eds[300];

void ans(int x) {
	cout << "! " << x << "\n";
	cout.flush();
}
int cnt = 0;

vector<int> ask(int x) {
	vector<int> vv;
	us[x] = 1;
	if (eds[x].empty()) {
		++cnt;
		if (cnt == 17) {
			return vv;
		}
		cout << "? " << x << "\n";
		cout.flush();
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			int y;
			cin >> y;
			eds[x].push_back(y);
		}
		if (eds[x].size() == 2u)
			return vv;
		return eds[x];
	}
	else {
		return eds[x];
	}
}

void solve() {
	cnt = 0;
	int h;
	cin >> h;
	for (int i = 1; i <= (1 << h); ++i)
		eds[i].clear(), us[i] = 0;
	vector<int> way;
	way.push_back(1);
	int now = 1;
	while (true) {
		vector<int> vv = ask(now);
		if (vv.empty()) {
			ans(now);
			return;
		}
		int fl = 0;
		for (int i: vv)
			if (!us[i]) {
				now = i;
				fl = 1;
				way.push_back(now);
				break;
			}
		if (!fl)
			break;
	}
	reverse(way.begin(), way.end());
	now = 1;
	while (true) {
		vector<int> vv = ask(now);
		if (vv.empty()) {
			ans(now);
			return;
		}
		int fl = 0;
		for (int i: vv)
			if (!us[i]) {
				now = i;
				fl = 1;
				way.push_back(now);
				break;
			}
		if (!fl)
			break;
	}
	int nh = h - 1 - (way.size() / 2);
	now = way[way.size() / 2];
	vector<int> vv = ask(now);
	for (int i: vv)
		if (!us[i]) {
			now = i;
			break;
		}
	--nh;
	while (true) {
		vector<int> vv = ask(now);
		if (vv.empty()) {
			ans(now);
			return;
		}
		if (nh == 1) {
			for (int i: vv) {
				if (ask(i).empty()) {
					ans(i);
					return;
				}
			}
			return;
		}
		if (nh == 2) {
			for (int i: vv) {
				vector<int> gg = ask(i);
				for (int j: gg)
					if (ask(j).empty()) {
						ans(j);
						return;
					}
			}
			return;
		}
		way.clear();
		way.push_back(now);
		int go = h - 1 - nh;
		int now2 = now;
		for (int i = 0; i < go; ++i) {
			vector<int> vv = ask(now2);
			if (vv.empty()) {
				ans(now2);
				return;
			}
			for (int j: vv) {
				if (!us[j]) {
					way.push_back(j);
					now2 = j;
					break;
				}
			}
		}
		if (ask(way.back()).empty()) {
			ans(way.back());
			return;
		}
		if (ask(way.back()).size() == 1u) {
			vector<int> gg = ask(now);
			for (int i: gg)
				if (!us[i]) {
					now = i;
					break;
				}
		}
		else {
			now = way[1];
			for (int i = 2; i < (int)way.size(); ++i)
				us[way[i]] = 0;
		}
		--nh;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}