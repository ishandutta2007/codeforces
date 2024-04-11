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

const ld PI = acos(-1.0);

const int M = 4e6; 
int rev[M];
cld wpw[M];

void fft(vc &a, int n, bool f) {
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);

    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2.0L * PI / len * (f ? -1.0L : 1.0L);
        int l2 = len >> 1;

        cld wl(cos(ang), sin(ang));
        wpw[0] = cld(1, 0);
        for (int i = 1; i < l2; i++)
            wpw[i] = wpw[i-1] * wl;

        cld t;
        int l, r;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
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

cld pot (cld b, ll p) {
    cld res = 1;

    while (p) {
        if (p&1)
            res *= b;
        b *= b; 
        p >>= 1;
    }

    return res;
}

void potencia (vc &a, int k) {
    vc b(a.begin(), a.end());
    a = vc(b.size());
    a[0] = 1;
    int ln = 10;

    while (k) {
        a.resize(a.size()*2, 0);
        b.resize(b.size()*2, 0);

        obtRev(a.size(), ++ln);

        fft(b, b.size(), 0);

        if (k & 1) {
            fft(a, a.size(), 0);
            for (int i = 0; i < a.size(); i++)
                a[i] *= b[i];

            fft(a, a.size(), 1);
            for (int i = 0; i < a.size(); i++)
                if (ll(a[i].real()+0.5))
                    a[i] = 1;
                else
                    a[i] = 0;
        }

        for (int i = 0; i < b.size(); i++)
            b[i] *= b[i];

        fft(b, b.size(), 1);
        for (int i = 0; i < b.size(); i++)
            if (ll(b[i].real()+.5))
                b[i] = 1;
            else
                b[i] = 0;

        k >>= 1;
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k, x;

    cin >> n >> k;

    vc a(1024);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x] = 1;
    }

    potencia(a, k);

    for (int i = 0; i < a.size(); i++) 
        if (ll(a[i].real()+0.5))
            cout << i << " ";
    cout << endl;

    return 0;
}