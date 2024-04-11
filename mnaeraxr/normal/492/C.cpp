#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, r, avg;
	cin >> n >> r >> avg;
	vector<pii> e(n);
	int64 s = 0;
	for (int i = 0; i < n; ++i){
		cin >> e[i].second >> e[i].first;
		s += e[i].second;
	}

	int64 ans = 0;

	sort(e.begin(), e.end());

	for (int i = 0; s < n * avg; ++i){
		if (s + (r - e[i].second) < n * avg){
			s += (r - e[i].second);
			ans += (r - e[i].second) * e[i].first;
		}
		else{
			ans += (n * avg - s) * e[i].first;
			s = n * avg;
		}
		// cout << "-" << endl;
		// cout << e[i].second << " " << e[i].first << endl;
		// cout << ans << " " << s << endl;
	}

	cout << ans << endl;

	return 0;
}