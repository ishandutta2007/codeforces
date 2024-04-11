#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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

int n, k;
string s;

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

void solve () {
	cin >> n >> k >> s;
	
	string res;
	int ind = n - 1;
	
	vi zf = obtZF(s);
	
	for (int i = n - 2; i >= 0; i--) {
		int j = zf[i + 1];
		
		if (j > ind)
			continue;
		
		if (s[j] <= s[(i + 1 + j) % (ind + 1)])
			ind = i;
	}
	
	int j = 0;
	while (res.size() < k) {
		res.pb(s[j]);
		j++;
		if (j > ind)
			j = 0;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}