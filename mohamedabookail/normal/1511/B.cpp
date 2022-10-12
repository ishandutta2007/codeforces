/**
*    author:  Mohamed Abo Okail
*    created: 13/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		string s1(a, '0'), s2(b, '0');
		s1[0] = s2[0] = '1';
		s1[a - c] = '1';
		cout << s1 << ' ' << s2 << endl;
	}
}