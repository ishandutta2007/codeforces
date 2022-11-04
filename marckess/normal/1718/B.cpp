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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105, lim = 60;
int n;
ll c[MX], fibo[MX], pos[MX][lim], tot;

void main_() {
	cin >> n;
	
	memset(pos, 0, sizeof(pos));
	tot = 0;
	
	forn (i, n) {
		cin >> c[i];
		tot += c[i];
		
		ll aux = c[i];
		for (int j = lim - 1; j >= 0; j--) {
			if (fibo[j] <= aux) {
				pos[i][j] = 1;
				aux -= fibo[j];
			}
		}
		
		if (pos[i][2] == 1 && pos[i][1] == 1) {
			pos[i][1] = 0;
			pos[i][0] = 1;
		}
	}
	
	ll sum = 0, i = -1;
	while (sum < tot) {
		i++;
		sum += fibo[i];
	}
	
	if (sum != tot) {
		cout << "NO" << endl;
		return;
	}
	
	/*while (i >= 0) {
		vi v;
		forn (j, n)
			if (pos[j][i])
				v.pb(j);
		
		if (v.size() == 0 || v.size() > 2) {
			cout << "NO" << endl;
			return;
		} 
		
		if (v.size() == 2) {
			if (i % 2) {
				cout << "NO" << endl;
			}
		}
		
		i--;
	} */
	
	int last = -1;
	while (i >= 0) {
		int f = 0;
		
		vi v;
		forn (j, n)
			if (c[j] >= fibo[i] && j != last) {
				v.pb(j);
				f = 1;
			}
		
		if (!f) {
			cout << "NO" << endl;
			return;
		}
		
		sort(all(v), [&] (int i, int j) {
			return c[i] > c[j];
		});
		
		last = v[0];
		c[v[0]] -= fibo[i];
		
		i--;
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fibo[0] = fibo[1] = 1;
	forr (i, 2, lim - 1)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}