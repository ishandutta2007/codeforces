/**
 *    author:  Mohamed Abo_Okail
 *    created: 19/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	double ans = 0.00;
	for (int i = 1; i <= n; i++) {
		ans += (1 / double(i));
	}
	cout << fixed << setprecision(12) << ans << endl;
}