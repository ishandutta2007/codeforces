#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 2 * (1e5);
const int M = (1<<20);
int count[M]; // times a string appears

set<int> conns[N]; // 
int size[N];
bool handled[N];
int label[N];
long long ans[N];

void getapps(int i, int p, int c, vector<int>& apps) {
	c ^= label[i];
	apps.push_back(c);
	for (auto t : conns[i]) {
		if (t == p) continue;
		getapps(t, i, c, apps);
	}
}
long long helper(int i, int p, int c) {
	long long res = 0;
	c ^= label[i];
	res += count[c];
	for (int j = 1; j < M; j <<= 1) {
		res += count[c ^ j];
	}
	for (auto t : conns[i]) {
		if (t == p) continue;
		res += helper(t, i, c);
	}
	ans[i] += res;
	return res;
}

void solve(int i) {
	// cout << "SOLVE " << i << '\n';

	long long res = 0;
	vector<vector<int>> apps (conns[i].size());
	// add counts
	int j = 0;
	for (auto t : conns[i]) {
		getapps(t, i, label[i], apps[j]);
		// cout << "CONN TO " << t << '\n';
		for (auto it : apps[j]) {
			// cout << it << ' ';
			++count[it];
		}
		// cout << '\n';
		++j;
	}
	++count[label[i]];
	// remove self counts, then count possibilities, then add self counts
	j = 0;
	for (auto t : conns[i]) {
		for (auto it : apps[j]) {
			--count[it];
		}
		res += helper(t, i, 0);
		for (auto it : apps[j]) {
			++count[it];
		}
		++j;
	}
	// count paths ending in i
	res += count[0];
	for (int j = 1; j < M; j <<= 1) res += count[j];
	// double counted everything
	res += 1; // expect path to self
	res >>= 1;
	// remove counts
	j = 0;
	for (auto t : conns[i]) {
		for (auto it : apps[j]) {
			--count[it];
		}
		++j;
	}
	--count[label[i]];
	// remove conns from others
	for (auto t : conns[i]) {
		conns[t].erase(i);
	}
	// finish handling
	ans[i] += res;
	handled[i] = true;
}

int calc_size(int i, int p) {
	int res = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		res += calc_size(t, i);
	}
	size[i] = res;
	return res;
}
int find_centroid(int i, int p, int s) {
	if (i == p) s = calc_size(i, i);
	if (size[i] * 2 < s) return -1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		int sub = find_centroid(t, i, s);
		if (sub != -1) return sub;
	}
	return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		conns[a].insert(b);
		conns[b].insert(a);
	}

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		int ind = (str[i] - 'a');
		label[i] = 1<<ind;
	}

	for (int i = 0; i < n; ++i) {
		while(!handled[i]) {
			int cen = find_centroid(i, i, 0);
			solve(cen);
		}
		cout << ans[i] << ' ';
	}
	cout << '\n';
}