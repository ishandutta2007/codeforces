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

	int t; cin >> t;
	while (t--){
		double a, b, ans;
		cin >> a >> b;

		if (a < 1e-5){
			if (b < 1e-5)
				ans = 1;
			else
				ans = 0.5;
		}
		else{
			if (4 * b < a){
				ans = 1.0 - b / a;
			}
			else{
				ans = (1.0 / 2 + a / 16 / b);
			}
		}
		cout.precision(17);
		cout << fixed << ans << endl;
	}

	return 0;
}