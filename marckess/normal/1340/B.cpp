#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, k, mem[MX][MX], to[MX][MX], num[10], a[MX];

int tomk (string s) {
	int res = 0;
	forn (i, s.size())
		res |= (int(s[i] == '1') << i);
	return res;
}

int dp (int i, int k) {
	if (k < 0) return 0;
	if (i == n) return k == 0;

	int &res = mem[i][k];
	if (res != -1) return res;
	res = 0;

	for (int j = 9; j >= 0; j--)
		if ((num[j] & a[i]) == a[i]) {
			int x = __builtin_popcount(num[j] ^ a[i]);
			if (dp(i + 1, k - x)) {
				res = 1;
				to[i][k] = j;
				break;
			}
		}

	return res;
}

void rec (int i, int k) {
	if (i == n) return;
	int j = to[i][k];
	int x = __builtin_popcount(num[j] ^ a[i]);
	cout << j;
	rec(i + 1, k - x);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	num[0] = tomk("1110111");		
	num[1] = tomk("0010010");
	num[2] = tomk("1011101");
	num[3] = tomk("1011011");
	num[4] = tomk("0111010");
	num[5] = tomk("1101011");
	num[6] = tomk("1101111");
	num[7] = tomk("1010010");
	num[8] = tomk("1111111");
	num[9] = tomk("1111011");

	cin >> n >> k;
	forn (i, n) {
		string s;
		cin >> s;
		a[i] = tomk(s);
	}

	if (dp(0, k)) {
		rec(0, k);
		cout << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}