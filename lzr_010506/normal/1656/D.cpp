#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T --)
	{
		ll n;
		cin >> n;
		if(n & 1) cout << "2\n";
		else
		{
			ll p = 1;
			ll ans;
			while(p <= n)
			{
				if(p == n) {cout << "-1\n"; goto L1;}
				if(n % p) break;
				p <<= 1;
			}
		//	cout << "p:" << p << "\n";
			ans = n / (p / 2);
			ans = min(ans, p);
			cout << ans << "\n";
			L1:;
		}
	}
	
	return 0;
}