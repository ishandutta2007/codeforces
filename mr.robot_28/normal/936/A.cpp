#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, d, t;
	cin >> k >> d >> t;
	int u1 = k / d + (k % d != 0);
	int m1 = d * u1 - k;
	int r1 = t * 2 / (d * u1 + k);
	double rn = ((t * 1.0 - r1 * k * 1.0 - r1 * m1 * 1.0 / (2)));
	if(rn >= k)
	{
		rn = (rn - k) * 2 + k;
	}
	rn += r1 * d * u1;
	cout << fixed << setprecision(10) << rn;
    return 0;
}