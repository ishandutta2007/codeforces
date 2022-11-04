#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll cn[3][1000005], acu = 0;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;

	for (int i = 1; i < s.size(); i++) {
		cn[0][i] = acu;
		if (s[i] == s[i-1] && s[i] == 'v')
			acu++;
	}

	acu = 0;
	for (int i = 2; i < s.size(); i++) {
		cn[1][i] = acu;
		if (s[i] == 'o')
			acu += cn[0][i];
	}

	acu = 0;
	for (int i = 3; i + 1 < s.size(); i++) {
		cn[2][i] = acu;
		if (s[i] == s[i+1] && s[i] == 'v')
			acu += cn[1][i];
	}

	cout << acu << endl;

	return 0;
}