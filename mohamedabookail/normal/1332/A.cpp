/**
 *    author:  Mohamed Abo_Okail
 *    created: O1/O4/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll x, x1, x2, y, y1, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool bol = 1;
		if(!a || !b) {
			if(!a && x + b > x2) bol = 0;
			if(!b && x - a < x1) bol = 0;
		}
		else {
			if(a >= b) {
				if(x - 1 >= x1 || x + 1 <= x2) {
					if(x - (a - b) < x1) bol = 0;
				}
				else bol = 0;
			}
			else {
				if(x - 1 >= x1 || x + 1 <= x2) {
					if(x + (b - a) > x2) bol = 0;
				}
				else bol = 0;
			}
		}
		if(!c || !d) {
			if(!c && y + d > y2) bol = 0;
			if(!d && y - c < y1) bol = 0;
		}
		else {
			if(c >= d) {
				if(y - 1 >= y1 || y + 1 <= y2) {
					if(y - (c - d) < y1) bol = 0;
				}
				else bol = 0;
			}
			else {
				if(y - 1 >= y1 || y + 1 <= y2) {
					if(y + (d - c) > y2) bol = 0;
				}
				else bol = 0;
			}
		}
		cout << (bol ? "Yes" : "No") << o_o;
	}
}