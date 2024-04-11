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

bool isComp (int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 1;
	return 0;
}

void main_() {
	ll x, d;
	cin >> x >> d;
	
	int pw = 0;
	while (x % d == 0) {
		x /= d;
		pw++;
	}
	
	if (pw < 2) {
		cout << "NO" << endl;
		return;
	}
	
	if (isComp(x)) {
		cout << "YES" << endl;
		return;
	}
	
	if (pw > 3 && isComp(d)) {
		cout << "YES" << endl;
		return;
	}
	
	if (pw == 3) {
		for (int i = 2; i * i <= d; i++)
			if (d % i == 0) {
				int a = d / i;
				int b = i;
				
				if (x * d * a % (d * d) && d * b % (d * d)) {
					cout << "YES" << endl;
					return;
				}
				
				if (x * d * b % (d * d) && d * a % (d * d)) {
					cout << "YES" << endl;
					return;
				}
			}
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