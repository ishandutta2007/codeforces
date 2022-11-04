
// Problem : C. Delete Two Elements
// Contest : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1598/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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
int n;
ll a[MX];

void main_() {
	cin >> n;
	
	ll sum = 0;
	forn (i, n) {
		cin >> a[i];
		
		a[i] *= 2;
		sum += a[i];
	}
	
	if (sum % n) {
		cout << 0 << endl;
		return;
	}
	
	sum /= n;
	
	map<ll, ll> mp;
	ll res = 0;
	
	forn (i, n) {
		res += mp[sum - a[i]];
		mp[a[i] - sum]++;
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