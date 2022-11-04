#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 20005;
int n, m, k, l[MX + 5], r[MX + 5], acu[2 * MX + 10], res;

int inter (int a, int b, int c, int d) {
	return max(min(b, d) - max(a, c) + 1, 0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	n += MX;
	
	forn (i, m) {
		cin >> l[i] >> r[i];
		l[i] += MX;
		r[i] += MX; 
	}
	
	for (int i = MX + 1; i + k - 1 <= n; i++) {
		memset(acu, 0, sizeof(acu));
		int fi = 0;
		
		forn (j, m) {
			int d = inter(i, i + k - 1, l[j], r[j]);
			fi += d;
			
			if (d == k || d == r[j] - l[j] + 1) continue;
			
			int izq_ini = l[j] - k + 1;
			int izq_fin = izq_ini + min(k, r[j] - l[j] + 1) - 1;
			int der_fin = r[j];
			int der_ini = der_fin - min(k, r[j] - l[j] + 1) + 1;
			
			/*if (d == 1) {
				cout << l[j] - MX << "," << r[j] - MX << ":" << endl;
				cout << izq_ini - MX << "->" << izq_fin - MX << " - " << der_ini - MX << "," << der_fin - MX << endl;
			}*/
			
			acu[izq_ini + d]++;
			acu[izq_fin + 1]--;
			
			acu[der_ini + 1]--;
			acu[der_fin - d + 2]++;
		}
		
		int se = 0, s = 0;
		
		forn (i, n + 1) {
			if (i) acu[i] += acu[i - 1];
			s += acu[i];
			se = max(se, s);
		}
		
		res = max(res, fi + se);
	}
	
	cout << res << endl;
	
	return 0;
}