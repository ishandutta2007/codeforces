#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 400005;
ll n, m, a[MX]; 
map<int, int> mp;

ll l2 (int n) {
	int res = 0, x = 1;
	while (x < n) {
		x *= 2;
		res++;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);

	ll res = n, i = 0, j = 0;
	while (i < n) {
		while (j < n) {
			mp[a[j]]++;
			j++;
			if (n * l2(mp.size()) > 8 * m) {
				j--;
				mp[a[j]]--;
				if (!mp[a[j]]) mp.erase(a[j]);
				break;
			}
		}
		res = min(res, i + int(n) - j);
		mp[a[i]]--;
		if (!mp[a[i]]) mp.erase(a[i]);
		i++;
	}

	cout << res << endl;
 
	return 0;
}