#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	int w1 = p / w;
	for(int i = 0; i < min(w1 + 1, d); i++)
	{
		if((p - (w1 * w - i * w)) % d == 0)
		{
			if(w1 - i + (p - (w1 * w - i * w)) / d <= n)
			{
				cout << w1 - i << " " << (p - (w1 * w - i * w)) / d << " " << n - (w1 - i) - (p - (w1 * w - i * w)) / d;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}