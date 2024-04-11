#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
	int n, s;
	cin >> n >> s;
	vector<pii> v(n);
	for (int i = 0; i < n; ++i){
		int x, y, k;
		cin >> x >> y >> k;
		v[i] = make_pair(x * x + y * y, k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n && s < 1000000; ++i){
		s += v[i].second;
		if (s >= 1000000){
			cout.precision(10);
			cout << fixed << sqrt(v[i].first) << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
}