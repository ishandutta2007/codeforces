/**
 *    author:  Mohamed.Abo_Okail
 *    created: 21/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n , m, k;
	cin >> n >> m >> k;
	ll ans = 0;
	while(k--) {
		ans += (2 * n) + (2 * m) - 4;
		n -= 4;
		m -= 4;
	}
	cout << ans << endl;
}