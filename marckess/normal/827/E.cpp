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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef complex<ld> cld;
typedef vector<cld> vc;

const int MX = 2222222;
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

void mul (vc &a, vc &b) {
    int n = 1, ln = 0;

    while (n < a.size())
        n *= 2, ln++;
    n *= 2, ln++;
    obtRev(n, ln);

    a.resize(n);
    b.resize(n);

    fft(a, n, 0);
    fft(b, n, 0);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];

    fft(a, n, 1);
    for (int i = 0; i < n; i++) {
        a[i].real(ll(a[i].real() + 0.5));
        a[i].imag(0);
    }
}

bitset<MX> bs;

void solve () {
	int n;
	string s;

	cin >> n >> s;

	vc a(2 * n + 2), b(2 * n + 2);

	for (int i = 0; i < n; i++) {
		if (s[i] == 'V') a[n+i+1] = 1;
		if (s[i] == 'K') b[n-i-1] = 1;
	}

	mul(a, b);

	for (int i = 1; i <= n; i++)
		bs[i] = !bool(a[2*n+i].real() + a[2*n-i].real());

	for (int i = n; i; i--)
		for (int j = 2 * i; j <= n; j += i)
			bs[i] = bs[i] & bs[j];

	vi res;
	for (int i = 1; i <= n; i++)
		if (bs[i])
			res.pb(i);

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}