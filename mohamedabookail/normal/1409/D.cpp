/**
*    author:  Mohamed Abo_Okail
*    created: O4/O9/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ull unsigned long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

ull ok(string s) {
	ull sum = 0;
	for (int i = 0; i < sz(s); i++) {
		sum = sum * 10 + (s[i] - '0');
	}
	return sum;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n; cin >> n;
		string cur = s;
		for (int i = sz(s) - 1; i >= 0 ; i--) {
			int flag = 0;
			for (auto ch : s) {
				flag += ch - '0';
			}
			if(flag <= n) break;
			if(!i) {
				s[i] = '1';
				s.push_back('0');
				break;
			}
			s[i] = '0';
			if(s[i - 1] < '9') {
				s[i - 1]++;
			}
			else {
				for (int j = i - 1; j >= 0 ; j--) {
					if(s[j] == '9') s[j] = '0';
					else {
						s[j]++;
						i = j + 1;
						break;
					}
				}
			}
		}
		if(s[0] == '0') {
			s[0] = '1';
			s.push_back('0');
		}
		cout << ok(s) - ok(cur) << endl;
	}
}