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

int n;
string s;

void main_() {
	cin >> n >> s;
	ll res = 0;
	forr (i, 0, n - 1) {
		vi cn(10);
		int mx = 0, x = 0;
		
		for (int j = i; j < n && j - i < 111; j++) {
			int c = s[j] - '0';
			if (!cn[c])
				x++;
			mx = max(mx, ++cn[c]);
			
			if (mx <= x)
				res++;
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