/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector < pair < ll, ll > > v(n);
	vector < ll > ans;
	ll nemo = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = (i + 1);
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		nemo += (cnt * v[i].first + 1);
		ans.push_back(v[i].second);
		cnt++;
	}
	cout << nemo << o_o;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}