/**
*    author:  Mohamed Abo Okail
*    created: 18/O9/2O22
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
		vector < string > a(n), b(n);
		map < string , int > mpA, mpB;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mpA[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			mpB[b[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if(mpB[a[i]]) {
				mpA[a[i]]--;
				mpB[a[i]]--;
			}
		}
		vector < int > tempA, tempB;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if(mpA[a[i]]) {
				if(sz(a[i]) == 1) {
					tempA.push_back(a[i][0] - '0');
				}
				else {
					tempA.push_back(sz(a[i]));
					ans++;
				}
				mpA[a[i]]--;
			}
		}
		for (int i = 0; i < n; i++) {
			if(mpB[b[i]]) {
				if(sz(b[i]) == 1) {
					tempB.push_back(b[i][0] - '0');
				}
				else {
					tempB.push_back(sz(b[i]));
					ans++;
				}
				mpB[b[i]]--;
			}
		}
		map < int , int > mpA2, mpB2;
		for (int i = 0; i < sz(tempA); i++) {
			mpA2[tempA[i]]++;
		}
		for (int i = 0; i < sz(tempB); i++) {
			mpB2[tempB[i]]++;
		}
		for (int i = 0; i < sz(tempA); i++) {
			if(mpB2[tempA[i]]) {
				mpA2[tempA[i]]--;
				mpB2[tempA[i]]--;
			}
		}
		for (int i = 0; i < sz(tempA); i++) {
			if(mpA2[tempA[i]]) {
				mpA2[tempA[i]]--;
				ans += tempA[i] != 1;
			}
		}
		for (int i = 0; i < sz(tempB); i++) {
			if(mpB2[tempB[i]]) {
				mpB2[tempB[i]]--;
				ans += tempB[i] != 1;
			}
		}
		cout << ans << endl;
	}
}