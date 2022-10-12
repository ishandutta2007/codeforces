/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = min((c / 2), b);
		b -= min((c/ 2), b);
		ans += min((b / 2), a);
		cout << ans * 3 << endl;
	}
}