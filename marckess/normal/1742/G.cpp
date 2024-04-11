#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 200005;
int n, a[MX], ex[MX];
vi pos[30];

void main_() {
	cin >> n;
	
	forn (j, 30)
		pos[j].clear();
	
	forn (i, n) {
		cin >> a[i];
		ex[i] = 0;
		
		forn (j, 30)
			if (a[i] & (1 << j))
				pos[j].pb(i);
	}
	
	int pre = 0;
	for (int j = 29; j >= 0; j--) {
		int act = 0, ind = -1;
		
		if (pre & (1 << j))
			continue;
		
		for (int i : pos[j])
			if (!ex[i])
				if ((pre | a[i]) > (pre | act)) {
					act = a[i];
					ind = i;
				}
		
		if (ind != -1) {
			cout << act << " ";
			ex[ind] = 1;
			pre |= act;
		}
	}
	
	forn (i, n)
		if (!ex[i])
			cout << a[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}