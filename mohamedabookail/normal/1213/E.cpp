/**
*    author:  Mohamed Abo_Okail
*    created: 27/1O/2O2O
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
	ll n; cin >> n;
	string a, b; cin >> a >> b;
	string s1[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
	string s2[] = {"abcabc", "acbacb", "bacbac", "bacbac", "cabcab", "cbacba"};
	string ans = "";
	for (int i = 0; i < 6; i++) {
		string s = s1[i];
		string x, y;
		x.push_back(s[0]);
		x.push_back(s[1]);
		y.push_back(s[1]);
		y.push_back(s[2]);
		if(a[0] == a[1] || b[0] == b[1]) break;
		if(a != x && b != y && a != y && b != x) {
			string ss(n, s[0]), sss(n, s[1]), ssss(n, s[2]);
			ans = ss + sss + ssss;
			break;
		}
	}
	for (int i = 0; i < 6; i++) {
		if(sz(ans)) break;
		string s = s2[i];
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			string x;
			x.push_back(s[j]);
			x.push_back(s[j + 1]);
			if(x != a && x != b) {
				cnt++;
			} 
		}
		if(cnt == 5) {
			string ss;
			ss.push_back(s[0]);
			ss.push_back(s[1]);
			ss.push_back(s[2]);
			for (int i = 0; i < n; i++) {
				ans += ss;
			}
			break;
		}
	}
	cout << "YES" << endl << ans << endl;
}