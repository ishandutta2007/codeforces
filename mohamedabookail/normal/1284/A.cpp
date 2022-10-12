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
	int n, m; cin >> n >> m;
	vector < string > a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) { cin >> a[i]; }
	for (int i = 1; i <= m; i++) { cin >> b[i]; }
	int q; cin >> q;
	while(q--) {
		int x; cin >> x;
		int aa = x % n, bb = x % m;
		if(!aa) { aa = n; }
		if(!bb) { bb = m; }
		cout << a[aa] << b[bb] << endl; 
	}
}