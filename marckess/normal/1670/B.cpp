// Powered by CP Editor (https://cpeditor.org)

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

int n, k, ex[256];
string s;

void main_() {
	cin >> n >> s >> k;
	
	memset(ex, 0, sizeof(ex));
	forn (i, k) {
		char c;
		cin >> c;
		ex[c] = 1;
	}
	
	int res = 0, last = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (last != -1)
			res = max(res, last - i);
			
		if (ex[s[i]])
			last = i;
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