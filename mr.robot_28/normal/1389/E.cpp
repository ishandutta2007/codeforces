#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m, d, w;
		cin >> m >> d >> w;
		if((d - 1) % w == 0)
		{
			int k = min(m, d);
			cout << k * (k - 1) / 2 << "\n";
		}
		else
		{
			int k = min(m, d);
			int w1 = w / __gcd(w, d - 1);
			int a = k % w1;
			int b = w1 - k % w1;
			int cnt2 = k / w1;
			int cnt1 = k / w1 + 1;
			cout << a * (cnt1 - 1) * cnt1 / 2 + b * (cnt2 - 1) * cnt2 / 2 << "\n";
		}
	}
  	return 0;
}