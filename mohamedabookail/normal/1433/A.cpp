/**
*    author:  Mohamed Abo_Okail
*    created: 21/1O/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int a = s[sz(s) - 1] - '0';
		int b = sz(s);
		cout << --a * 10 + b * (b + 1) / 2 << endl;
	}
}