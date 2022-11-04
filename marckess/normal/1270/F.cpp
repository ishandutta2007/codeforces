#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, SQ = 320;
int n, cn[MX * SQ + MX], acu[MX], ini[MX], fin[MX];
ll res = 0;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(ini, -1, sizeof(ini));
	memset(fin, -1, sizeof(fin));

	cin >> s;
	n = s.size();

	forn (i, n) {
		acu[i] = s[i] - '0';
		if (i)
			acu[i] += acu[i-1];
		
		if (acu[i])
			res += (i + 1) % acu[i] == 0;
		
		if (ini[acu[i]] == -1)
			ini[acu[i]] = i;
		fin[acu[i]] = i;
	}

	for (int k = 1; k < SQ; k++) {
		forn (i, n) {
			int x = i - k * acu[i];
			res += cn[x + MX * SQ]++;
		}

		forn(i, n) {
			int x = i - k * acu[i];
			cn[x + MX * SQ]--;
		}
		
		forn(i, n) {
			if (acu[i] - k < 0) continue;
			int a = ini[acu[i] - k], b = fin[acu[i] - k];

			b = min(b, i - SQ * k);
			a += MOD(i % k - a % k, k);
			b -= MOD(b % k - i % k, k);
			
			if (a <= b)
				res += 1 + (b - a) / k;
		}
	}

	cout << res << endl;

	return 0;
}