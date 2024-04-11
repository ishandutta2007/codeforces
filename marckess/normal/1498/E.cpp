#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, k[MX];
vvi a;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> k[i];
	
	forn (i, n)
		forn (j, i)
			a.pb({abs(k[i] - k[j]), i, j});
	
	sort(all(a), greater<vi>());
	
	for (vi &v : a) {
		int i = v[1];
		int j = v[2];
		if (k[i] < k[j]) swap(i, j);
		
		cout << "? " << i + 1 << " " << j + 1 << endl;
		string res;
		cin >> res;
		
		if (res == "Yes") {
			cout << "! " << i + 1 << " " << j + 1 << endl;
			return 0;
		}
	}
	
	cout << "! " << 0 << " " << 0 << endl;
	
	return 0;
}