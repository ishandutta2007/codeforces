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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 205;
int n, m;
ll k, lim = 1e18+1;
string f[15];

void solve () {
    vector<string> vs;
    for (int i = 0; i < f[n].size(); i++) {
        vs.pb(f[n].substr(i, f[n].size()-i));
    }

    sort(all(vs));
    for (int i = 0; i < min(m, (int)vs[k-1].size()); i++)
        cout << vs[k-1][i];

    cout << endl;
}

ll cn[MX];
bitset<MX> izq[MX], der[MX];

void pre (string s, int i) {
    cn[i] = 0;
    izq[i].reset(), der[i].reset();

    for (int j = 0; j + s.size() <= f[i].size(); j++)
        cn[i] += s == f[i].substr(j, s.size());

    for (int j = 1; j < s.size(); j++) {
    	izq[i][j] = s.substr(s.size()-j) == f[i].substr(0, j);
    	der[i][j] = s.substr(0, j) == f[i].substr(f[i].size()-j);
    }
}

ll obtRes (string s) {
    pre(s, 13), pre(s, 14);
    
    for (int i = 15; i <= n; i++) {
    	cn[i] = cn[i-2]+ cn[i-1];
    	for (int j = 1; j < s.size(); j++)
    		cn[i] += der[i-2][j] && izq[i-1][s.size()-j];
    	cn[i] = min(cn[i], lim);

    	izq[i] = izq[i-2], der[i] = der[i-1];
    }

    return cn[n];
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    f[0] = '0', f[1] = '1';
    for (int i = 2; i <= 14; i++)
        f[i] = f[i-2] + f[i-1];

    cin >> n >> k >> m;
    if (n <= 14) {
        solve();
        return 0;
    }

    string res;
    for (int i = 0; i < m; i++) {
        res.pb('0');
        ll d = obtRes(res);

        if (d < k) {
            k -= d;
            res.back() = '1';
        }

        if (res == f[14].substr(f[14].size() - res.size())) k--;

        if (!k) {
        	cout << res << endl;
        	return 0;
        }
    }

    cout << res << endl;

    return 0;
}