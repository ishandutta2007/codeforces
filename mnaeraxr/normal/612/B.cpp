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
	vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i){
		int val; cin >> val;
		v[val] = i;
	}

	int64 ans = 0;
	for (int i = 2; i <= n; ++i)
		ans += abs(v[i] - v[i - 1]);

	cout << ans << endl;

	return 0;
}