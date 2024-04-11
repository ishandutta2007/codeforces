/**
 *    author:  Mohamed.Abo_Okail
 *    created: 01/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, h, m; cin >> n >> h >> m;
	vector <int> v(n + 1, h);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			if(v[j] != h) { v[j] = min(v[j], c); }
			else { v[j] = c; }
		}
	} ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += pow(v[i], 2);
	}
	cout << ans << endl;
}