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

typedef complex<ld> cld;
typedef vector<cld> vc;

const int MX = 4000005;
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

int n, m, a;
bitset<MX> ned;
vc p;
vi res;

void norm (vc &a, int n) {
	for (int i = 0; i < n; i++) {
	    a[i].real(ll(a[i].real() + 0.5));
	    a[i].imag(0);
    }
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	p.resize(m+1);

	while (n--) {
		cin >> a;
		ned[a] = 1;

		if (!p[a].real())
			for (int b = a; b <= m; b += a)
				p[b] = 1;
	}

	p[0] = 1;

	n = 1;
	int ln = 0;
    while (n < p.size())
        n *= 2, ln++;
    n *= 2, ln++;
    obtRev(n, ln);
    p.resize(n);

	fft(p, n, 0);
	for (int i = 0; i < p.size(); i++)
		p[i] *= p[i];
	fft(p, n, 1);
	norm(p, n);

	for (int i = 1; i <= m; i++) {
		if (p[i].real()) {
			if (!ned[i]) {
				cout << "NO" << endl;
				return 0;
			}
			if (p[i].real() == 2)
				res.pb(i);
		}
	}

	cout << "YES" << endl;
	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}