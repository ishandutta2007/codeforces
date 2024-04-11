/**
*    author:  Mohamed Abo Okail
*    created: 08/12/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";

ll to_num(string s) {
	ll num = 0;
	for (int i = 0; i < sz(s); i++) {
		num = num * 10 + (s[i] - '0');
	}
	return num;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n, d;
	cin >> n >> d;
	ll mn = n - d;
	string sA = to_string(n);
	string sB = to_string(mn);
	if(sz(sB) < sz(sA)) {
		string ans(sz(sA) - 1 , '9');
		for (char ch = '9'; ch > '0'; ch--) {
			string cur = ch + ans;
			if(to_num(cur) > 0 && to_num(cur) <= n) {
				ans = cur;
				break;
			}
		}
		cout << ans << endl;
	}
	else {
		string ans = sA;
		reverse(all(sA));
		for (int i = 0; i < sz(sA) - 1; i++) {
			if(sA[i] == '9') continue;
			if(sA[i + 1] != '0') {
				sA[i] = '9';
				sA[i + 1]--;
			}
			else {
				sA[i] = '9';
				for (int j = i + 1; j < sz(sA); j++) {
					if(sA[j] == '0') {
						sA[j] = '9';
					}
					else {
						sA[j]--;
						break;
					}
				}
			}
			string dd = sA;
			reverse(all(dd));
			if(to_num(dd) >= mn) {
				ans = dd;
			}
			else {
				break;
			}
		}
		cout << ans << endl;
	}
}