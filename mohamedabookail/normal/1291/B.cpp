/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O2/2O2O
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
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		vector < ll > v(n);
		ll a = 0, b = 0, inx = -1;
		bool bol = 0, boll = 1;
		for (int i = 0; i < n; i++) { cin >> v[i]; }
		for (int i = 0; i < n; i++) {
			if(v[i] < a) { inx = i; break; }
			a++;
		}
		if(inx != -1) {
			for (int i = n - 1; i >= inx; i--) {
				if(v[i] < b) { boll = 0; break; }
				b++;
			}
		}
		if(b < a && boll) bol = 1;
		a = 0; b = 0; inx = -1; boll = 1;
		for (int i = n - 1; i >= 0; i--) {
			if(v[i] < a) { inx = i; break; }
			a++;
		}
		if(inx != -1) {
			for (int i = 0; i <= inx; i++) {
				if(v[i] < b) { boll = 0; break; }
				b++;
			}
		}
		if(b < a && boll) bol = 1;
		cout << (bol ? "Yes" : "No") << o_o;
	}
}