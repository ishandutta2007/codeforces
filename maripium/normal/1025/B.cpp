#include <bits/stdc++.h>
using namespace std;

const int N = 15e4 + 5;

int n;
int a[N], b[N];
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 2; i * i <= a[1]; ++i) if (a[1] % i == 0) {
		vec.push_back(i);
		while (a[1] % i == 0) a[1] /= i;
	}
	if (a[1] > 1) vec.push_back(a[1]);
	for (int i = 2; i * i <= b[1]; ++i) if (b[1] % i == 0) {
		vec.push_back(i);
		while (b[1] % i == 0) b[1] /= i;
	}
	if (b[1] > 1) vec.push_back(b[1]);
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 2; i <= n; ++i) {
		vector<int> new_vec;
		for (int v : vec) {
			if (a[i] % v == 0 || b[i] % v == 0) {
				new_vec.push_back(v);
			}
		}
		vec = new_vec;
	}
	
	cout << (vec.size() ? vec[0] : -1) << '\n';
}