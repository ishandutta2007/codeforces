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
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i){
		int mn, mx = max(v[i] - v[0], v[n - 1] - v[i]);
		if (i == 0)
			mn = v[1] - v[0];
		else if (i + 1 == n)
			mn = v[n - 1] - v[n - 2];
		else
			mn = min(v[i] - v[i - 1], v[i + 1] - v[i]);
		cout << mn << " " << mx << endl;
	}

	return 0;
}