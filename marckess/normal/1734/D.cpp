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

const int MX = 200005;
int n, k;
ll a[MX];

void main_() {
	cin >> n >> k;
	forr (i, 1, n)
		cin >> a[i];
	
	forn (kk, 2) {
		ll izq = 0, acu = 0, der = 0;
		int j = k;
		
		forr (i, k, n + 1) {
			der += a[i];
			if (izq + der < 0) {
				break;
			}
			
			while (j > 0 && acu + a[j - 1] + der >= 0) {
				acu += a[j - 1];
				izq = max(izq, acu);
				j--;
			}
			
			if (j == 0 || i == n + 1) {
				cout << "YES" << endl;
				return;
			}
		}
		
		reverse(a + 1, a + n + 1);
		k = n - k + 1;
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}