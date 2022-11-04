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
int n, w[MX], h[MX];

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> w[i] >> h[i];
	}
	int act = max(w[0], h[0]);
	forr (i, 1, n - 1) {
		if (max(w[i], h[i]) <= act)
			act = max(w[i], h[i]);
		else if (min(w[i], h[i]) <= act)
			act = min(w[i], h[i]);
		else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		main_();
	
	return 0;
}