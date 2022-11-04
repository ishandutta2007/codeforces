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

vi v;

void main_() {
	int n;
	cin >> n;
	
	cout << int(upper_bound(all(v), n) - v.begin()) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i * i <= 1000000000; i++)
		v.pb(i * i);
	for (int i = 1; i * i * i <= 1000000000; i++)
		v.pb(i * i * i);
	
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}