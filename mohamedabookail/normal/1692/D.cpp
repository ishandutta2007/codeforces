/**
*    author:  Mohamed Abo Okail
*    created: 26/O6/2O22
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

bool ok(string s) {
	string str = s;
	reverse(all(str));
	return (s == str);
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		string s;
		int n;
		cin >> s >> n;
		set < string > st;
		if(ok(s)) {
			st.insert(s);
		}
		int x = 2000;
		while(x--) {
			int a = (s[0] - '0') * 10 + (s[1] - '0');
			int b = (s[3] - '0') * 10 + (s[4] - '0');
			a += n / 60;
			b += n % 60;
			a += b / 60;
			b -= b / 60 * 60;
			if(a > 23) a -= 24;
			s[0] = (a / 10 + '0');
			s[1] = (a % 10 + '0');
			s[3] = (b / 10 + '0');
			s[4] = (b % 10 + '0');
			if(ok(s)) {
				st.insert(s);
			}
		}
		cout << sz(st) << endl;
	}
}