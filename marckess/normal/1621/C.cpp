// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

// #define endl '\n'
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

void main_() {
	int n;
	cin >> n;
	
	vi res(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		int act = -1;
		if (res[i] != -1) continue;
		
		while (1) {
			cout << "? " << i << endl;
			
			int r;
			cin >> r;
			if (act != -1)
				res[act] = r;
			
			if (!r) exit(0);
			
			if (res[r] != -1)
				break;
			act = r;
		}
	}
	
	cout << "!";
	forn (i, n)
		cout << " " << res[i + 1];
	cout << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}