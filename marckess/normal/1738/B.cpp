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
int n, k;
ll s[MX];

void main_() {
	cin >> n >> k;
	forn (i, k)
		cin >> s[i];
	
	forn (i, k - 2)
		if (s[i + 1] - s[i] > s[i + 2] - s[i + 1]) {
			cout << "No" << endl;
			return;
		}
	
	if (k > 1) {
		if (1ll * (n - k + 1) * (s[1] - s[0]) < s[0]) {
			cout << "No" << endl;
			return;
		}
	}
	
	cout << "Yes" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}