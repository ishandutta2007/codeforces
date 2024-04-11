#include <bits/stdc++.h>
using namespace std;

vector<int> cur; 
vector<int> res;

void reset(vector<int> &a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
}

void calc(vector<int> a,int k) {
	if (cur.size() > res.size()) return;
	if (!a.size()) {
		if (res.size() > cur.size()) {
			res = cur;
			return;
		}
	}
	
	if (k == 20) return;

	bool flag = 0;
	for (int &x : a) flag |= (x & 1);

	if (!flag) {
		vector<int> na;
		for (int &x : a) if (x / 2) na.push_back(x / 2);
		reset(na);
		calc(na, k + 1);
	}

	else {
		for (int i = -1; i <= 1; i += 2) {
			vector<int> na;
			for (int &x : a) {
				if (x & 1) {
					if ((x - i) / 2) na.push_back((x - i) / 2);
				} else {
					if (x / 2) na.push_back(x / 2);
				}
			}
			reset(na);
			cur.push_back(i * (1 << k));
			calc(na, k + 1);
			cur.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> a;
	while(n--) {
		int x; cin >> x; 
		if (x) a.push_back(x);
	}
	reset(a);
	res.assign(100, 0);

	calc(a, 0);
	
	cout << res.size() << endl;
	for (int &x : res) cout << x << ' ';
}