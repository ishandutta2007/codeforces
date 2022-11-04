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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 120;
ll der[MX][MX], aba[MX][MX], t;
int x, y;

void main_() {
	cin >> t >> x >> y;
	
	if (t < x + y) {
		cout << "NO" << endl;
		return;
	}
	
	t -= x + y;
	
	der[0][0] = (t + 1) >> 1;
	aba[0][0] = t >> 1;
	
	forr (d, 1, x + y) {
		int i = d < MX ? 0 : d - (MX - 1);
		int j = d - i;
		
		while (i < MX && j >= 0) {
			ll in = 0;
			
			if (i) in += aba[i - 1][j];
			if (j) in += der[i][j - 1];
		
			der[i][j] = (in + 1) >> 1;
			aba[i][j] = in >> 1;
			
			i++, j--;
		}
	}
	
	int i = 0, j = 0;
	
	while (i + j != x + y) {
		if (i >= MX || j >= MX) {
			cout << "NO" << endl;
			return;
		}
		
		if (der[i][j] == aba[i][j]) j++;
		else i++;
	}
	
	if (i == x && j == y) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}