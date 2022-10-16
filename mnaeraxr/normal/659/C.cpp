#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 m;
	cin >> n >> m;

	vector<int64> v(n);

	set<int> s;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
		s.insert(v[i]);
	}

	sort(v.begin(), v.end());
	vector<int64> acc(n + 1);
	for (int i = 0; i < n; ++i)
		acc[i + 1] = acc[i] + v[i];


	int64 lo = 0, hi = 10000000;

	while (lo + 1 < hi){
		int64 mid = (lo + hi) / 2;
		int p = upper_bound(v.begin(), v.end(), mid) - v.begin();
		int64 tot = mid * (mid + 1) / 2 - acc[p];
		if (tot <= m) lo = mid;
		else hi = mid;
	}

	int total = lo - (upper_bound(v.begin(), v.end(), lo) - v.begin());

	cout << total << endl;

	for (int i = 1; i <= lo; ++i){
		if (!s.count(i))
			cout << i << " ";
	}

	cout << endl;

	return 0;
}