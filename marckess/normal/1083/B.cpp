#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5e5+5;
int n;
ll res[MX], dob[MX], k;
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s >> t;

	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {

			res[i] = min(2ll, k);

			for (int j = i+1; j < n; j++) {
				if (s[j] == 'a') {
					dob[j]++;
					dob[j] = min(dob[j], k);

					res[j] += 1 + dob[j];
					res[j] = min(res[j], k);

					dob[j+1] += 2 * dob[j];
				} else {
					dob[j] =  min(dob[j], k);

					res[j] += 1 + dob[j];
					res[j] = min(res[j], k);

					dob[j+1] += 2 * dob[j];
				}
			}

			memset(dob, 0, sizeof(dob));

			for (int j = i+1; j < n; j++) {
				if (t[j] == 'b') {
					dob[j]++;
					dob[j] = min(dob[j], k);

					res[j] += 1 + dob[j];
					res[j] = min(res[j], k);

					dob[j+1] += 2 * dob[j];
				} else {
					dob[j] =  min(dob[j], k);

					res[j] += 1 + dob[j];
					res[j] = min(res[j], k);

					dob[j+1] += 2 * dob[j];
				}
			}

			break;
		}

		res[i] = 1;
	}

	ll acu = 0;
	for (int i = 0; i < n; i++) {
		//cout << res[i] << " ";
		acu += res[i];
	}
	cout << acu << endl;

	return 0;
}