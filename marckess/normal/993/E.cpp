#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef complex<ld> cld;
typedef vector<cld> vc;

const int MX = 200005;
const ld pi = acos(ld(-1));
vi rev;
vc wlpw;

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

vc mul (vc a, vc b) {
    int n = 1, ln = 0;

    while (n < max(a.size(), b.size()))
        n *= 2, ln++;
    n *= 2, ln++;

    rev.resize(n);
    wlpw.resize(n);
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

    return a;
}

int n, x, a[MX], b[MX], acu[MX];
bool f = 0;
vc pos, neg, d;
ll res[MX], tam = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        if (a[i] < x) {
            if (f) {
                f = 0;
                res[0] += tam * (tam + 1) / 2;
                tam = 0;
            }
            b[i] = 1;
        } else {
            f = 1;
            tam++;
        }
    }

    res[0] += tam * (tam + 1) / 2;

    acu[b[0]]++;
    for (int i = 1; i < n; i++) {
        b[i] += b[i-1];
        acu[b[i]]++;
    }

    pos.resize(2*n+3);
    neg.resize(2*n+3);

    neg[n+1].real(1 + acu[0]);
    pos[n+1].real(acu[0]);

    for (int i = 1; i <= n; i++) {
        neg[n+1-i].real(acu[i]);
        pos[n+1+i].real(acu[i]);
    }

    d = mul(pos, neg);

    for (int i = 1; i <= n; i++)
        res[i] = d[2*n+2+i].real();

    for (int i = 0; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}