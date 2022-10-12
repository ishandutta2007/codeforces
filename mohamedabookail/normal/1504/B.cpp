/**
*    author:  Mohamed Abo Okail
*    created: 21/1O/2O21
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
		int n; cin >> n;
		string a, b; cin >> a >> b;
		if(a == b) {
			cout << "YES" << endl;
			continue;
		}
		int indx = 0;
		for (int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				indx = i;
			}
		}
		int cnt0 = 0, cnt1 = 0;
		bool ok = 1;
		for (int i = 0; i <= indx; i++) {
			if(a[i] == b[i]) {
				ok &= (cnt0 == cnt1);
				for (int j = i; j <= indx; j++) {
					if(a[j] != b[j]) {
						i = j - 1;
						break;
					}
					cnt0 += (a[j] == '0');
					cnt1 += (a[j] == '1');
				}
				ok &= (cnt0 == cnt1);
			}
			else {
				cnt0 += (a[i] == '0');
				cnt1 += (a[i] == '1');
			}
		}
		ok &= (cnt0 == cnt1);
		cout << (ok ? "YES" : "NO") << endl;
	}
}