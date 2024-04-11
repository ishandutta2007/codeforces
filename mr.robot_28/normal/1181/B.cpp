#include <bits/stdc++.h>

using namespace std;

vector<int> t, x, y, ans;
string s;
int n;

void sum(vector<int> &v, vector<int> &u) {
	reverse(v.begin(), v.end());
	reverse(u.begin(), u.end());
	for (int i = 0; i < u.size(); i++) {
		if (i < v.size())
			v[i] += u[i];
		else
			v.push_back(u[i]);
	}
	for (int i = 0; i < (int)v.size() - 1; i++) {
		v[i + 1] += v[i] / 10;
		v[i] %= 10;
	}
	if (!v.empty()) {
		while (v.back() >= 10) {
			v.push_back(v.back() / 10);
			v[v.size() - 2] %= 10;
		}
	}
	reverse(v.begin(), v.end());
	reverse(u.begin(), u.end());
}

void mn(vector<int> &v, vector<int> &u) {
	if (v.size() < u.size())
		return;
	if (u.size() < v.size()) {
		v = u;
		return;
	}
	for (int i = 0; i < v.size(); i++)
		if (v[i] < u[i])
			break;
		else if (v[i] > u[i]) {
			v = u;
			break;
		}
}




int main() {
	cin >> n >> s;
	for (auto i : s)
		t.push_back(i - '0');
	int mid1 = n / 2, mid2 = (n - 1) / 2;
	while (mid1 < n && t[mid1] == 0)
		mid1++;
	while (t[mid2 + 1] == 0) {
		mid2--;
	}
	bool b = 1;
	if (mid1 < n) {
		for (int i = 0; i < mid1; i++)
			x.push_back(t[i]);
		for (int i = mid1; i < n; i++)
			y.push_back(t[i]);
		sum(x, y);
		ans = x;
	}
	else
		b = 0;
	if (mid2 >= 0) {
		x.clear();
		y.clear();
		for (int i = 0; i <= mid2; i++)
			x.push_back(t[i]);
		for (int i = mid2 + 1; i < n; i++)
			y.push_back(t[i]);
		sum(x, y);
		if (b)
			mn(ans, x);
		else
			ans = x;
	}
	for (auto i : ans)
		cout << i;
	return 0;
}