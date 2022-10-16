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

	int n, s = 0; cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		s += v[i];
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int fin = s / n;
	int tot = s % n;

	int ans = 0;

	for (int i = 0; i < n; ++i){
		if (i < tot) ans += abs(fin + 1 - v[i]);
		else ans += abs(fin - v[i]);
	}

	cout << ans / 2 << endl;
	
	return 0;
}