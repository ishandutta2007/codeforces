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
typedef float ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef complex<ld> cld;
typedef vector<cld> vc;

const int MX = 270000;
const ld pi = acos(ld(-1));
int rev[MX];
cld wlpw[MX];

void fft (vc& a, int n, bool inv) {
    for (int i = 0; i < n; i++ )
        if (i < rev[i])
            swap(a[i], a[rev[i]]);

    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * pi / len * (inv ? -1 : 1);
        cld wl (cos(ang), sin(ang));

        wlpw[0] = cld(1, 0);
        for (int i = 1; i < len / 2; i++)
            wlpw[i] = wlpw [i-1] * wl;
        
        cld t;
        int r, l;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
                r = i + j + len / 2; l = i + j;
                t = a[r] * wlpw[j];
                a[r] = a[l] - t;
                a[l] += t ;
            }
        }
    }

    if (inv)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}
 
void obtRev ( int n, int log_n ) {
    for (int i = 0; i < n; i++) {
        rev[i] = 0 ;
        for (int j = 0; j < log_n; j++)
            if (i & (1 << j))
                rev[i] |= 1 << (log_n - 1 - j) ;
    }
}

string s, t;
vc a[6], b[6], c[6][6];
vi adj[6];
int n, ln, vis, cn, m;

void init () {
	for (int i = 0; i < 6; i++) adj[i].clear();
	vis = cn = m = 0;
}

void dfs (int u) {
	m++;
	vis |= (1 << u);
	for (int v : adj[u])
		if (!(vis & (1 << v)))
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t;

	n = 1, ln = 0;
	while (n < max(s.size(), t.size()))
		n *= 2, ln++;
	n *= 2, ln++;
	obtRev(n, ln);

	for (int i = 0; i < 6; i++) {
		a[i].resize(n);
		for (int j = 0; j < s.size(); j++)
			if (s[j] == i+'a')
				a[i][j] = 1;

		b[i].resize(t.size());
		for (int j = 0; j < t.size(); j++)
			if (t[j] == i+'a')
				b[i][j] = 1;
		reverse(all(b[i]));
		b[i].resize(n);

		fft(a[i], n, 0);
		fft(b[i], n, 0);
	}

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			c[i][j].resize(n);

			for (int k = 0; k < n; k++)
				c[i][j][k] = a[i][k] * b[j][k];

			fft(c[i][j], n, 1);

			for (int k = 0; k < n; k++)
				c[i][j][k] = int(c[i][j][k].real()+0.5);
		}

	for (int k = 0; k <= s.size() - t.size(); k++) {
		init();

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				if (i != j && c[i][j][t.size()+k-1].real() != 0) {
					adj[i].pb(j);
					adj[j].pb(i);
				}

		for (int i = 0; i < 6; i++)
			if (adj[i].size()) {
				cn++;
				dfs(i);
			}

		cout << m - cn << " ";
	}
	cout << endl;

	return 0;
}