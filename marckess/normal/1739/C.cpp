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

const int MX = 66, mod = 998244353;
int n, a[MX], b[MX], c[MX][MX];

int comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	if (n == k || k == 0) return 1;
	
	int &res = c[n][k];
	if (res != -1) return res;
	
	return res = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod; 
}

void main_() {
	int n;
	cin >> n;
	cout << a[n] << " " << b[n] << " " << 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c, -1, sizeof(c));
	
	a[2] = 1, b[2] = 0;
	for (int i = 4; i < MX; i += 2) {
		a[i] = comb(i - 1, i / 2 - 1);
		b[i] = comb(i - 2, i / 2 - 2);
		
		(a[i] += b[i - 2]) %= mod;
		(b[i] += a[i - 2]) %= mod;
	}
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}