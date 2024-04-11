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
string l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	cin >> n >> l >> r;
	
	if (l[0] != r[0]) {
		forn (_, n)
			cout << 1;
		cout << endl;
		return 0;
	}
	
	int f = 1, g = 1;
	forn (i, n) {
		g &= f || l[i] == '1';
		f &= l[i] == r[i];
		
		if (!f && i + 1 == n)
			cout << int(r[i] == '1' || r[i - 1] == '1' || !g);
		else
			cout << r[i];
	}
	
	return 0;
}