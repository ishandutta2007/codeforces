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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, cn[256], res = 0;
string s;

int pr (int x) {
	return x * (x - 1) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> s;
		cn[s[0]]++;
	}

	for (int i = 'a'; i <= 'z'; i++)
		res += pr(cn[i] / 2) + pr((cn[i] + 1) / 2);
	cout << res << endl;

	return 0;
}