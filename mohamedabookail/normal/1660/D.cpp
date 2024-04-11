/**
*    author:  Mohamed Abo Okail
*    created: 31/O3/2O22
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

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < ll > a(n), x;
		ll cnt = 0, mx = 1e18;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 0) {
				x.push_back(i);
			}
			cnt += (a[i] < 0);
		}
		if(sz(x) == 0) {
			if(cnt % 2 == 0) {
				cout << "0 0" << endl;
			}
			else {
				ll s1 = 1, indx1 = 0;
				for (int i = 0; i < n; i++) {
					s1 *= a[i];
					if(a[i] < 0) {
						indx1 = i + 1;
						break;
					}
				}
				ll s2 = 1, indx2 = 0;
				for (int i = n - 1; i >= 0 ; i--) {
					s2 *= a[i];
					if(a[i] < 0) {
						indx2 = n - i;
						break;
					}
				}
				s1 *= -1;
				s2 *= -1;
				if(s1 >= s2) {
					cout << 0 << ' ' << indx2 << endl;
				}
				else {
					cout << indx1 << ' ' << 0 << endl;
				}
			}
		}
		else {
			vector < pair < ll , pair < ll , ll > > > any;
			x.push_back(-1);
			x.push_back(n);
			sort(all(x));
			for (int i = 1; i < sz(x); i++) {
				ll h = 1;
				for (int j = x[i - 1] + 1; j < x[i]; j++) {
					if(h * a[j] <= mx) { 
						h *= a[j];
					}
				}
				if(h > 0) {
					any.push_back(make_pair(h, make_pair(x[i - 1] + 1, n - x[i])));
				}
				else {
					ll indx1 = -1, indx2 = -1;
					for (int j = x[i - 1] + 1; j < x[i]; j++) {
						if(a[j] < 0 && indx1 == -1) {
							indx1 = j;
						}
						if(a[j] < 0) {
							indx2 = j;
						}
					}
					ll h1 = 1, h2 = 1;
					for (int j = x[i - 1] + 1; j < indx2; j++) {
						if(h1 * a[j] <= mx) {
							h1 *= a[j];
						}
					}
					for (int j = indx1 + 1; j < x[i]; j++) {
						if(h2 * a[j] <= mx) {
							h2 *= a[j];
						}
					}
					int cnt1 = indx1 - (x[i - 1] + 1), cnt2 = x[i] - indx2 - 1;
					if(h1 >= h2) {
						any.push_back(make_pair(h1, make_pair(x[i - 1] + 1, n - (x[i] - 1) + cnt2)));
					}
					else {
						any.push_back(make_pair(h2, make_pair(x[i - 1] + 2 + cnt1, n - x[i])));
					}
				}
			}
			sort(all(any));
			cout << any[sz(any) - 1].second.first << ' ' << any[sz(any) - 1].second.second << endl;
		}
	}
}