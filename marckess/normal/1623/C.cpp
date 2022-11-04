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

const int MX = 200005;
int n;
ll a[MX], b[MX];

bool esPos (int m) {
	forn (i, n)
		b[i] = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		b[i] += a[i];
		if (b[i] < m) return 0;
		
		if (i < 2) continue;
		
		int d = min((b[i] - m) / 3, a[i] / 3);
		b[i] -= 3 * d;
		b[i - 1] += d;
		b[i - 2] += 2 * d; 
	}
	
	return 1;
}

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	int l = 1, r = 1e9, rep = 30;
	while (rep--) {
		int m = (l + r + 1) / 2;
		if (esPos(m)) l = m;
		else r = m;
	}
	cout << l << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}