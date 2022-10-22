#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxd = 10;

string s;
int n;
string quer[Maxn];
ii p[Maxd];

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> quer[i];
	for (int i = 0; i < Maxd; i++)
		p[i] = ii(i, 10);
	for (int i = n - 1; i >= 0; i--) {
		ii cur = ii(0, 1);
		for (int j = 3; j < quer[i].length(); j++) {
			int dig = quer[i][j] - '0';
			cur.first = (ll(cur.first) * p[dig].second + p[dig].first) % mod;
			cur.second = ll(cur.second) * p[dig].second % mod;
		}
		p[quer[i][0] - '0'] = cur;
	}
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		int dig = s[i] - '0';
		res = (ll(res) * p[dig].second + p[dig].first) % mod;
	}
	cout << res << endl;
	return 0;
}