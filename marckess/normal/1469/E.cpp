#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi obtZF (string &s) {
    int n = s.size();
    vi zf(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zf[i] = min (r - i + 1, zf[i - l]);
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
            zf[i]++;
        if (i + zf[i] - 1 > r)
            l = i, r = i + zf[i] - 1;
    }
    
    return zf;
}

int n, k, vis[1 << 20], col;
string s, res;

void solve () {
	cin >> n >> k >> s;
	
	res.clear();
	forn (kk, k - 20)
		res.pb('1');
	
	int r = min(20, k);
	string t = res + s;
	vi zf = obtZF(t);
	col++;
	
	for (int i = res.size(); i + k <= t.size(); i++)
		if (zf[i] >= res.size()) {
			int acu = 0, b = 1;
			for (int j = i + k - 1, l = 0; l < r; j--, l++, b *= 2)
				acu += int(t[j] - '0') * b;
			
			vis[acu] = col;
		}
	
	for (int i = (1 << r) - 1; i >= 0; i--)
		if (vis[i] != col) {
			string aux;
			
			forn (j, r)
				if (i & (1 << j))
					aux.pb('1');
				else
					aux.pb('0');
			
			reverse(all(aux));
			res += aux;
			
			for (char &c : res)
				c ^= 1;
	
			cout << "YES" << endl << res << endl;
			return;
		}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}