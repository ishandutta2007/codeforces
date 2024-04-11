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
typedef vector<ll> vl;
typedef vector<ii> vii;

int n;
set<vi> st, res;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	vi x(n);

	forn (j, n) {
		cout << "? 0 " << j << endl;
		cin >> x[j];
	}

	forn (i, n) {
		int f = 1;
		vi p(n, -1);
		
		forn (j, n) {
			if ((i ^ x[j]) >= n || p[i ^ x[j]] != -1) {
				f = 0;
				break;
			}
			p[i ^ x[j]] = j;
		}

		if (f && p[0] == i)
			st.insert(p);
	}

	forn (j, n) {
		cout << "? " << j << " " << 0 << endl;
		cin >> x[j];
	}

	forn (i, n) {
		int f = 1;
		vi p(n, -1);

		forn (j, n) {
			if ((i ^ x[j]) >= n || p[j] != -1) {
				f = 0;
				break;
			}
			p[j] = i ^ x[j];
		}

		if (f && p[i] == 0 && st.count(p))
			res.insert(p);
	}

	cout << "!" << endl;
	cout << res.size() << endl;
	for (int r : *res.begin())
		cout << r << " ";
	cout << endl;

	return 0;
}