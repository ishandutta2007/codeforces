/**
 *    author:  Mohamed.Abo_Okail
 *    created: 29/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector <ll> x(a), y(b);
		for (int i = 0; i < a; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < b; i++) {
			cin >> y[i];
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if(x[a - 1] > y[b - 1]) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}