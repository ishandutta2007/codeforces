#include <bits/stdc++.h>

#define endl '\n'
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;

int go (int n) {
	int k = 1111111111;
	int res = 0;
	
	while (k && n) {
		res += n / k;
		n %= k;
		k /= 10;
	}
	
	return res;
}

void solve () {
	cin >> n;
	
	int x = n / 11;
	int y = x * 11;
	
	while ((n - y) % 100 != 0) {
		y -= 11;
		x--;
	}
	
	if (y < 0) {
		cout << "NO" << endl;
		return;
	}
	
	if (go((n - y) / 100) <= x) cout << "YES" << endl;
	else cout << "NO" << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}