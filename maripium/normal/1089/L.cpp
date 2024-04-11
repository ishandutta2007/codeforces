#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k;
int a[N], b[N];
vector<int> vals[N];
vector<int> cand;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) scanf("%d", b + i);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) vals[a[i]].push_back(b[i]);
	for (int i = 1; i <= k; ++i) {
		if (vals[i].empty()) cnt++;
		else {
			sort(vals[i].begin(), vals[i].end());
			vals[i].pop_back();
			for (int v : vals[i]) cand.push_back(v);
		}
	} 
	sort(cand.begin(), cand.end());
	long long sum = 0;
	for (int i = 0; i < cnt; ++i) sum += cand[i];
	cout << sum << '\n';
}