/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O5/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector < string > v(n);
		string s;
		bool bol = 1, bolx = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < m; i++) {
			string t;
			char chAns = 'a';
			int mn = 10, cnt = 0;
			for (int j = 0; j < n; j++) {
				string tt = v[j];
				t.push_back(tt[i]);
			}
			for (char ch = 'a'; ch <= 'z'; ch++) {
				cnt = 0;
				for (int j = 0; j < n; j++) {
					if(t[j] != ch) cnt++;
				}
				if(cnt <= mn) {
					chAns = ch;
					mn = cnt;
				}
			}
			s.push_back(chAns);
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			string t = v[i];
			for (int j = 0; j < m; j++) {
				if(s[j] != t[j]) cnt++;
			}
			if(cnt > 1) bol = 0;
			if(cnt > 2) bolx = 1;
		}
		if(bol) { cout << s << endl; continue; }
		if(bolx) { cout << -1 << endl; continue; }
		bool bolfinal = 0;
		for (int i = 0; i < m; i++) {
			for (char ch = 'a'; ch <= 'z'; ch++) {
				string t = s;
				t[i] = ch;
				bool boly = 1;
				for (int j = 0; j < n; j++) {
					int cnt = 0;
					string tt = v[j];
					for (int k = 0; k < m; k++) {
						if(t[k] != tt[k]) cnt++;
					}
					if(cnt > 1) boly = 0;
				}
				if(boly) {
					bolfinal = 1;
					s = t;
					break;
				}
			}
			if(bolfinal) break;
		}
		cout << (bolfinal ? s : "-1") << endl;
	}
}