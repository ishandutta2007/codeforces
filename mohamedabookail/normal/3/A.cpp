/**
 *    author:  Mohamed Abo_Okail
 *    created: O9/O6/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
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
	char ch1, ch2, a, b; cin >> ch1 >> a >> ch2 >> b;
	if(ch1 == ch2) {
		cout << abs(a - b) << endl;
		char ch = (a > b ? 'D' : 'U');
		for (int i = 0; i < abs(a - b); i++) {
			cout << ch << endl;
		}
	}
	else if(a == b) {
		cout << abs(ch1 - ch2) << endl;
		char ch = (ch1 > ch2 ? 'L' : 'R');
		for (int i = 0; i < abs(ch1 - ch2); i++) {
			cout << ch << endl;
		}
	}
	else {
		vector < string > v;
		if(a > b) {
			if(ch1 < ch2) {
				while(ch1 != ch2 && a != b) {
					v.push_back("RD");
					ch1++;
					a--;
				}
				if(a == b) {
					for (int i = 0; i < abs(ch1 - ch2); i++) {
						v.push_back("R");
					}
				}
				if(ch1 == ch2) {
					for (int i = 0; i < abs(a - b); i++) {
						v.push_back("D");
					}
				}
			}
			else {
				while(ch1 != ch2 && a != b) {
					v.push_back("LD");
					ch1--;
					a--;
				}
				if(a == b) {
					for (int i = 0; i < abs(ch1 - ch2); i++) {
						v.push_back("L");
					}
				}
				if(ch1 == ch2) {
					for (int i = 0; i < abs(a - b); i++) {
						v.push_back("D");
					}
				}
			}
		}
		else {
			if(ch2 > ch1) {
				while(ch1 != ch2 && a != b) {
					v.push_back("RU");
					ch1++;
					a++;
				}
				if(a == b) {
					for (int i = 0; i < abs(ch1 - ch2); i++) {
						v.push_back("R");
					}
				}
				if(ch1 == ch2) {
					for (int i = 0; i < abs(a - b); i++) {
						v.push_back("U");
					}
				}
			}
			else {
				while(ch1 != ch2 && a != b) {
					v.push_back("LU");
					ch1--;
					a++;
				}
				if(a == b) {
					for (int i = 0; i < abs(ch1 - ch2); i++) {
						v.push_back("L");
					}
				}
				if(ch1 == ch2) {
					for (int i = 0; i < abs(a - b); i++) {
						v.push_back("U");
					}
				}
			}
		}
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}
}