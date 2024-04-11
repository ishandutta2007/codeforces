/**
*    author:  Mohamed AboOkail
*    created: 15/02/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		long long n;
		cin >> n;
		if(n & 1) {
			vector < pair < int , int > > pr(n + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if(pr[i].first < n / 2) {
						if(pr[i].first + 1 <= n / 2 && abs(pr[j].second - 1) <= n / 2) { 
							pr[i].first++;
							pr[j].second--;
							cout << 1 << ' ';
						}
						else {
							pr[i].first--;
							pr[j].second++;
							cout << -1 << ' ';
						}
					}
					else {
						if(abs(pr[i].second - 1) <= n / 2 && (pr[j].first + 1) <= n / 2) {
							pr[i].second--;
							pr[j].first++;
							cout << -1 << ' ';
						}
						else {
							pr[i].second++;
							pr[j].first--;
							cout << 1 << ' ';
						}
					}
				}
			}
			cout << "\n";
		}
		else {
			vector < pair < pair < int , int > , int > > pr(n + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if(pr[i].second < 1) {
						pr[i].second = 1;
						pr[j].second = 1;
						cout << 0 << ' ';
					}
					else if(pr[i].first.first < (n - 1) / 2) {
						if(pr[i].first.first + 1 <= (n - 1) / 2 && abs(pr[j].first.second - 1) <= (n - 1) / 2) {
							pr[i].first.first++;
							pr[j].first.second--;
							cout << 1 << ' ';
						}
						else {
							pr[i].first.first--;
							pr[j].first.second++;
							cout << -1 << ' ';
						}
					}
					else {
						if(abs(pr[i].first.second - 1) <= (n - 1) / 2 && (pr[j].first.first + 1) <= (n - 1) / 2) {
							pr[i].first.second--;
							pr[j].first.first++;
							cout << -1 << ' ';
						}
						else {
							pr[i].first.second++;
							pr[j].first.first--;
							cout << 1 << ' ';
						}
					}
				}
			}
			cout << "\n";
		}
	}
}