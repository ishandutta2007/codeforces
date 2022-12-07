#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
ll acu[MX];

void main_() {
	cin >> n;
	forr (i, 1, n) {
		cin >> a[i];
		acu[i] = acu[i - 1] + a[i];
	}
	
	int res = 0, f = 0;
	forr (i, 1, n) {
		if (a[i] == 0) {
			map<ll, int> mp;
			int mx = 1;
			mp[acu[i]]++;
			
			int j = i + 1;
			while (j <= n && a[j]) {
				mp[acu[j]]++;
				mx = max(mx, mp[acu[j]]);
				j++;
			}
			
			res += mx;
			f = 1;
		} else if (!f) {
			res += acu[i] == 0;
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}