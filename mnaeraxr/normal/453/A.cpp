#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;

int n, m;

ld dexp(ld v, int p){
	if (!p) return 1.0;
	ld ans = dexp(v * v, p / 2);
	if (p & 1) ans *= v;
	return ans;
}

ld prob(int k){
	ld v = (ld)k / n;
	return dexp(v, m);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	double ans = 0;	

	for (int k = 1; k <= n; ++k)
		ans += 1.0 * k * ( prob(k) - prob(k - 1) );

	cout.precision(6);
	cout << fixed << ans << endl;

	return 0;
}