/**
*    author:  Mohamed Abo Okail
*    created: 30/O9/2O21
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
		priority_queue < pair < ll , ll > > pq;
		vector < pair < ll , ll > > ans;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if(!x) continue;
			pq.push(make_pair(x, i + 1));
		}
		while(sz(pq) > 1) {
			ll a = pq.top().first;
			ll aa = pq.top().second;
			pq.pop();
			ll b = pq.top().first;
			ll bb = pq.top().second;
			pq.pop();
			a--;
			b--;
			ans.push_back(make_pair(aa, bb));
			if(a) {
				pq.push(make_pair(a, aa));
			}
			if(b) {
				pq.push(make_pair(b, bb));
			}
		}
		cout << sz(ans) << endl;
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}
}