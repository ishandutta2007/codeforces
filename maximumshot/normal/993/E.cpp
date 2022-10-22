#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

typedef complex< ld > base;
const ld PI = acos(-1.0);

int rev (int num, int lg_n) {
    int res = 0;
    for (int i=0; i<lg_n; ++i)
        if (num & (1<<i))
            res |= 1<<(lg_n-1-i);
    return res;
}

void fft (base *a, int n, bool invert) {
    int lg_n = 0;
    while ((1 << lg_n) < n)  ++lg_n;

    for (int i=0; i<n; ++i)
        if (i < rev(i,lg_n))
            swap (a[i], a[rev(i,lg_n)]);

    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            int len_2 = len / 2;
            for (int j=0; j<len_2; ++j) {
                base u = a[i+j],  v = a[i+j+len_2] * w;
                a[i+j] = u + v;
                a[i+j+len_2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

inline ll func(int n) {
    return 1ll * n * (n + 1) / 2;
}

const int N = 8e5 + 5;

int n, x, k;
int a[N];
int p[N];
ll res[N];
ll A[N];
ll B[N];
ll C[N];
int sz;
base fa[N];
base fb[N];

void mul () {
    for(int i = 0;i < sz;i++) {
        fa[i] = A[i];
        fb[i] = B[i];
    }
    size_t n = 1;
    int nn = 1;
    while (nn < sz)  nn <<= 1;
    nn <<= 1;

    fft (fa, nn, false),  fft (fb, nn, false);
    for (size_t i=0; i<nn; ++i)
        fa[i] *= fb[i];
    fft (fa, nn, true);

    for (size_t i=0; i< nn; ++i)
        C[i] = ll (fa[i].real() + 0.5);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    cin >> n >> x;

    p[0] = 0;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = a[i] < x;
        if(a[i]) p[++k] = i;
    }

    p[k + 1] = n + 1;

    if(k == 0) {
        cout << func(n) << " ";
        for(int i = 1;i <= n;i++) {
            cout << "0 ";
        }
        cout << "\n";
        return 0;
    }

    for(int i = 0;i <= k;i++) {
        res[0] += func(p[i + 1] - p[i] - 1);
    }

    for(int i = 1;i <= k;i++) {
        A[i] = p[i + 1] - p[i];
    }

    for(int i = 0;i <= k;i++) {
        B[n - i] = p[i + 1] - p[i];
    }

    sz = n + 1;

    mul();

//    for(int i = 0;i <= n;i++) {
//        for(int j = 0;j <= n;j++) {
//            C[i + j] += 1ll * A[i] * B[j];
//        }
//    }

    for(int i = 1;i <= k;i++) {
        res[i] += C[n + i];
    }

    for(int i = 0;i <= n;i++) {
        cout << res[i] << " ";
    }

    cout << "\n";

    return 0;
}