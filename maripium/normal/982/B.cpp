#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int w[N];
int f[N];
vector<int> res;
typedef pair<int,int> ii;
set<ii> s1, s2;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> w[i];
		s2.insert(ii(w[i], i));
	}
	vector<int> res;
	for (int i = 0;i < (n << 1);++i) {
		char c; cin >> c;
		if (c == '0') {
			ii u = *s2.begin();
			res.push_back(u.second);
			f[u.second] = 1;
			s2.erase(u);
			s1.insert(ii(-u.first, u.second));
		} else {
			ii u = *s1.begin();
			res.push_back(u.second);
			s1.erase(u);
		}
	}
	for (int i = 0;i < 2 * n;++i) cout << res[i] << ' ';
}