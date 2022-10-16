#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int l = 0, ans = 0;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	for (auto vv : v){
		if (vv.second > l){
			l = vv.first;
			++ans;
		}
	}

	cout << ans << endl;

	return 0;
}