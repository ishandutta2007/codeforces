#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define DBN(n) cerr << #n << "=" << n << "\n";
#define DB(n) cerr << #n << "=" << n << " ";
#define FI(n) for (int i = 0; i < (n); ++i)
#define FJ(n) for (int j = 0; j < (n); ++j)
#define FK(n) for (int k = 0; k < (n); ++k)
#define FQ(n) for (int q = 0; q < (n); ++q)


const int MAX_N = 300333;


int d[MAX_N];
		
int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (k == 2) {
		cout << n - 1 << '\n';
		for (int i = 2; i <= n; i++) {
			cout << i << ' ' << i - 1 << '\n';
		}
		return 0;
	}
	vector<pair<int, int>> ans;
	deque<int> leafs;
	for (int i = 1; i <= k; i++) {
		d[i + 1] = 1;
		ans.push_back({1, i + 1});
		leafs.push_back(i + 1);
	}
	int cnt = k + 1;
	while (cnt < n) {
		int v = leafs.front();
		leafs.pop_front();
		ans.push_back({v, ++cnt});
		leafs.push_back(cnt);
		d[cnt] = d[v] + 1;
	}
	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);
	
	cout << d[1] + d[2] << '\n';
	for (auto p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}

	
	return 0;
}