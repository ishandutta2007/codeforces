/**
 *    author:  Mohamed Abo_Okail
 *    created: O4/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector <ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if(n == 1) {
		return cout << 0 << endl, 0;
	}
	ll ans = 0, a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if(a > b) {
			b += v[n - 1];
			n--;
			i--;
		}
		else if(b > a) {
			a += v[i];
		}
		else {
			ans = max(ans, a);
			a += v[i];
		}
	}
	if(a == b) { ans = a; }
	cout << ans << endl;
}