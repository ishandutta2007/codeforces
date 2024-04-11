#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int64 oo = 0x3f3f3f33f3f3f3f;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 k;
	cin >> n >> k;
	++n;

	vector<int64> coef(n);
	vector<int64> acc(n + 1);

	for (int i = 0; i < n; ++i){
		cin >> coef[i];
	}

	for (int i = n - 1; i >= 0; --i){
		acc[i] = acc[i + 1] * 2 + coef[i];
		if (abs(acc[i]) >= oo) acc[i] = oo;
	}

	int ans = 0;

	int64 v = 0;

	for (int i = 0; i < n; ++i){
		if (acc[i] < oo){
			int64 tmp = coef[i] - (v + acc[i]);

			if (i + 1 < n || tmp != 0)
				if (abs(tmp) <= k) ++ans;
		}

		v += coef[i];
		if (v & 1) break;
		v /= 2;
	}

	cout << ans << endl;

	return 0;
}