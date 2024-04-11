// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 5005;
int n, m, pre[MX], suf[MX];
string s, t;

vi obtZF (string s) {
	int n = s.size();
	vi zf(n + 2);
	
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

string reverse (string s) {
	reverse(all(s));
	return s;
}

void main_() {
	cin >> n >> m >> s >> t;
	
	for (int i = 0, j = 0; j < m; i++, j++) {
		while (i < n && s[i] != t[j])
			i++;
		
		if (i == n) {
			cout << -1 << endl;
			return;
		}
		
		pre[j] = i;
	}
	
	for (int i = n - 1, j = m - 1; j >= 0; i--, j--) {
		while (s[i] != t[j])
			i--;
		
		suf[j] = i;
	}
	
	int res = 1e9;
	
	for (int s1 = 0; s1 <= n; s1++) {
		vi l = obtZF(reverse(s.substr(0, s1)) + reverse(t));
		vi r = obtZF(s.substr(s1) + t);
		
		for (int t1 = 0; t1 <= m; t1++) {
			if (t1 && pre[t1 - 1] > s1 - 1) continue;
			if (t1 < m && suf[t1] < s1) continue;
			
			int p = 0;
			if (s1 < n)
				p += (n - s1) - r[(n - s1) + t1];
			
			if (s1)
				p += s1 - l[s1 + (m - t1)] + 1 + (s1 - t1);
			
			res = min(res, p);
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