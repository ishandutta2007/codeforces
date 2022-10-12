/**
*    author:  Mohamed Abo Okail
*    created: 12/O9/2O22
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
		int n, h, m;
		cin >> n >> h >> m;
		vector < pair < int , int > > ar(n);
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i].first >> ar[i].second;
			ok |= (ar[i].first == h && ar[i].second == m);
		}
		if(ok) {
			cout << "0 0" << endl;
			continue;
		}
		sort(all(ar));
		for (int i = 0; i < n; i++) {
			if(ar[i].first > h || (ar[i].first == h && ar[i].second > m)) {
				ar[0].first = ar[i].first;
				ar[0].second = ar[i].second;
				break;
			}
		}
		int H = 0, M = 0;
		if(ar[0].first < h || (ar[0].first == h && ar[0].second < m)) {
			ar[0].first += 24;
		}
		H = ar[0].first - h;
		if(ar[0].second < m) {
			H--;
			ar[0].second += 60;
		}
		M = ar[0].second - m;
		cout << H << ' ' << M << endl;
	}
}