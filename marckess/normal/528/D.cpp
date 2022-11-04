#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

typedef complex<ld> cld;
typedef vector<cld> vc;

const int M = 800000;
const ld PI = acos(ld(-1));
int rev[M];
cld wpw[M];

void fft (vc &a, int n, bool f) {
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);

    for (int len = 2; len <= n; len *= 2) {
        ld ang = 2 * PI / len * (f ? -1 : 1);

        cld wl(cos(ang), sin(ang));
        wpw[0] = 1;
        for (int i = 1; i < len/2; i++)
            wpw[i] = wpw[i-1] * wl;

        cld t;
        int l, r;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len/2; j++) {
                l = i+j, r = i+j+len/2;
                t = a[r] * wpw[j];
                a[r] = a[l] - t;
                a[l] += t;
            }
        }
    }

    if (f)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}

void obtRev (int n, int ln) {
    for (int i = 0; i < n; i++) {
        rev[i] = 0;
        for (int j = 0; j < ln; j++)
            if (i & (1 << j))
                rev[i] |= 1 << (ln - j - 1);
    }
}

void multiplica (vc &a, vc & b) {
    int n = 1, ln = 0;
    while (n < max(a.size(), b.size()))
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
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vc a[255], b[255];
    char mv[] = {'A', 'T', 'C', 'G'};
    string s, t;
    int k;

    cin >> k >> k >> k >> s >> t;
    reverse(t.begin(), t.end());

    for (int l = 0; l < 4; l++) {
        int ult = -1e9;
        a[mv[l]] = vc(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == mv[l])
                ult = i;
            if (i - ult <= k)
                a[mv[l]][i] = 1;
        }

        ult = 1e9;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == mv[l])
                ult = i;
            if (ult - i <= k)
                a[mv[l]][i] = 1;
        }

        b[mv[l]] = vc(t.size());
        for (int i = 0; i < t.size(); i++)
            if (t[i] == mv[l])
                b[mv[l]][i] = 1;
    }

    vi co(255);
    for (int i = 0; i < t.size(); i++)
        co[t[i]]++;

    for (int l = 0; l < 4; l++)
        multiplica(a[mv[l]], b[mv[l]]);

    int res = 0;
    for (int i = t.size()-1; i < s.size(); i++) {
        bool f = true;
        for (int l = 0; l < 4; l++)
            f &= ll(a[mv[l]][i].real()+0.5) == co[mv[l]];
        if (f)
            res++;
    }

    cout << res << endl;

    return 0;
}