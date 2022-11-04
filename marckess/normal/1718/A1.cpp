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
int n, a[MX], mem[MX][2 * MX];

int dp (int i, int j) {
	if (i == n) return 0;
	
	int &res = mem[i][j];
	if (res != -1) return res;
	
	return res = min(
		dp(i + 1, a[i + 1]) + bool(j),
		dp(i + 1, a[i + 1] ^ j) + bool(j)
	);
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		memset(mem[i], -1, sizeof(mem[i]));
	}
	cout << dp(0, a[0]) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}