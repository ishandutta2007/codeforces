
// Problem : E. Rescue Niwen!
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/E
// Memory Limit : 512 MB
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

const int MX = 5005;
int n, zf[MX][MX], mem[MX];
string s;

void obtZF (string &s, int zf[MX]) {
    int n = s.size();
    
    forn (i, n)
    	zf[i] = 0;

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            zf[i] = min(r - i + 1, zf[i - l]);
            
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
            zf[i]++;
        
        if (i + zf[i] - 1 > r)
            l = i, r = i + zf[i] - 1;
    }
}

int dp (int i) {
	int &res = mem[i];
	if (res != -1)
		return res;
	res = 0;
	
	for (int j = i + 1; j < n; j++) {
		int k = zf[i][j - i];
		
		if (j + k == n) continue;
		if (s[i + k] > s[j + k]) continue;
		
		res = max(res, dp(j) + n - (j + k));
	}
	
	return res;
}

void solve () {
	cin >> n >> s;
	
	forn (i, n) {
		string t = s.substr(i);
		obtZF(t, zf[i]);
	}
	
	memset(mem, -1, sizeof(mem));
	
	int res = 0;
	forn (i, n)
		res = max(res, dp(i) + n - i);
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}