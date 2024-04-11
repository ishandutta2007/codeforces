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

const int MX = 100005;
int n, q, a[MX];
ll sum[MX], acu[MX];
vi pos;

ll f (int l, int r) {
	return (sum[r] - sum[l - 1]) - (acu[r] ^ acu[l - 1]);
}

void main_() {
	cin >> n >> q;
	
	pos.clear();
	
	forr (i, 1, n) {
		cin >> a[i];
		
		sum[i] = a[i] + sum[i - 1];
		acu[i] = a[i] ^ acu[i - 1];
		
		if (a[i])
			pos.pb(i);
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		int rl = l, rr = r;
		ll res = f(l, r);
		
		int i = lower_bound(all(pos), l) - pos.begin();
		if (i == pos.size() || pos[i] > r) {
			cout << l << " " << l << endl;
			return;
		}
		
		int ini_j = upper_bound(all(pos), r) - pos.begin();
		ini_j--;
		
		int ci = 0;
		for (i; i <= ini_j && ci <= 30; i++, ci++)
		for (int j = ini_j, cj = 0; j >= i && cj <= 30; j--, cj++) {
			ll p = f(pos[i], pos[j]);
			
			if (p > res) {
				p = res;
				rl = pos[i];
				rr = pos[j];
			} else if (p == res) {
				if (pos[j] - pos[i] < rr - rl) {
					rl = pos[i];
					rr = pos[j];
				}
			}
		}
		
		cout << rl << " " << rr << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}