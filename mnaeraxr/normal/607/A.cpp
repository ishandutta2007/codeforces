#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	map<int,int> m;

	int ans = 1;

	for (int i = 0; i < n; ++i){
		int a = v[i].first, b = v[i].second;
		auto f = m.lower_bound(a - b);

		if (f == m.begin()) m[a] = 1;
		else{
			--f;
			m[a] = 1 + f->second;
		}
		
		ans = max(ans, m[a] + 1);
	}

	cout << n + 1 - ans << endl;

	return 0;
}