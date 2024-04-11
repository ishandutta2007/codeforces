/**
*    author:  Mohamed Abo Okail
*    created: 17/01/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if(a > c) {
			swap(a, c);
		}
		if(b - a == c - b) {
			cout << "YES" << endl;
		}
		else if(a == b && a % c == 0) {
			cout << "YES" << endl;
		}
		else if(b == c && b % a == 0) {
			cout << "YES" << endl;
		}
		else if(a == c && a % b == 0) {
			cout << "YES" << endl;
		}
		else if((c - a) % 2 == 0 && (a + (c - a) / 2) % b == 0) {
			cout << "YES" << endl;
		}
		else if(b > c && (b + (b - c)) % a == 0 && (b + (b - c)) > 0) {
			cout << "YES" << endl;
		}
		else if(b > c && (b + (b - a)) % c == 0 && (b + (b - a)) > 0) {
			cout << "YES" << endl;
		}
		else if(b < c && b - a >= 0 && (b + (b - a)) % c == 0) {
			cout << "YES" << endl;
		}
		else if(b < c && (b - (c - b)) % a == 0 && (b - (c - b)) > 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}