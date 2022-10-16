#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (n == 4 || k < n + 1){
		cout << -1 << endl;
		exit(0);
	}

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	vector<int> v;
	for (int i = 1; i <= n; ++i){
		if (i != a && i != b && i != c && i != d)
			v.push_back(i);
	}

	cout << a << " " << c << " ";
	for (auto val : v) cout << val << " ";
	cout << d << " " << b << endl;

	cout << c << " " << a << " ";
	for (auto val : v) cout << val << " ";
	cout << b << " " << d << endl;

	return 0;
}