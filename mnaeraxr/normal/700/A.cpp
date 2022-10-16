#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

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

	int n, k;
	double l, v1, v2;

	cin >> n >> l >> v1 >> v2 >> k;

	int t = (n + k - 1) / k;

	if (t == 1){
		cout.precision(17);
		cout << fixed << l / v2 << endl;
	}
	else{
		double y = l * (1 + v2 / v1) / (2.0 * t - 1 + v2 / v1);
		double x = l - y;
		double a = y / v2 + x / v1;

		cout.precision(17);
		cout << fixed << a << endl;
	}

	return 0;
}