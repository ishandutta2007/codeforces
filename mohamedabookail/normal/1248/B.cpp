/**
 *    author:  Mohamed Abo_Okail
 *    created: 27/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < ll > v(n);
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//if(n == 1) { return cout << v[0] << o_o, 0; }
	for (int i = 0; i < n; i++) {
		if(i < n / 2) {
			a += v[i];
		}
		else {
			b += v[i];
		}
	}
	cout << (a * a) + (b * b) << o_o;
}