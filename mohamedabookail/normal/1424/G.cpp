/**
*    author: Mohamed AboOkail
*    created: O5/1O/2O2O
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
	int n; cin >> n;
	vector < pair < ll, ll > > p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(all(p));
	vector < ll > a, b(n);
	map < ll, bool > mp;
	for (int i = 0; i < n; i++) {
		if(!mp[p[i].first]) {
			a.push_back(p[i].first);
			mp[p[i].first] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		b[i] = p[i].second;
	}
	sort(all(b));
	map < ll, ll > mpx;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		mx = b[i];
		ll lo = 0, hi = sz(a) - 1, mid = 0, ans = -1;
		while(lo <= hi) {
			mid = (lo + hi) / 2;
			if(a[mid] >= mx) {
				ans = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		if(ans != -1) {
			mpx[a[ans]]++;
		}
	}
	for (int i = 1; i < sz(a); i++) {
		mpx[a[i]] += mpx[a[i - 1]];
	}
	ll ans = 0, cnt = 0, flag = 0;
	for (int i = 0; i < n; i++) {
		cnt = i + 1 - mpx[p[i].first];
		if(cnt > ans) {
			ans = cnt;
			flag = p[i].first;
		}
	}
	cout << flag << ' ' << ans << endl;
}