#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> base;

const ld pi = acos(-1.0l);
const ld eps = 0.001l;
const int Maxn = 200005;
const int Maxm = Maxn + Maxn;
const int Maxl = 26;
 
int nxt[Maxl];
bool tk[Maxl];
int head[Maxl], id[Maxl];
int cycles, clen[Maxl];
char A[Maxn], B[Maxn];
int alen, blen;
int S[Maxm];
int slen;
int Z[Maxm];
vector <base> V1, V2, V3;
char res[Maxn];

void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        ld ang = 2*pi/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

void multiply (const vector<base> & a, const vector<base> & b, vector<base> & res) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
 
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = fa[i];
}

void prepareFirst(vector <base> &V)
{
    V.resize(alen);
    for (int i = 0; i < alen; i++) {
        ld ang = 2.0l * pi / clen[head[A[i] - 'a']] * id[A[i] - 'a'];
        V[alen - 1 - i] = complex(cos(ang), sin(ang));
    }
}

void prepareSecond(vector <base> &V, char X[], int xlen)
{
    V.resize(xlen);
    for (int i = 0; i < xlen; i++) {
        ld ang = pi / clen[head[X[i] - 'a']] - 2.0l * pi / clen[head[X[i] - 'a']] * id[X[i] - 'a'];
        V[i] = complex(cos(ang), sin(ang));
    }
}
 
int main()
{
    for (int i = 0; i < Maxl; i++) {
        scanf("%d", &nxt[i]); nxt[i]--;
    }
    for (int i = 0; i < Maxl; i++) if (!tk[i]) {
        int cur = i;
        int pnt = 0;
        while (!tk[cur]) {
            tk[cur] = true;
            head[cur] = cycles;
            id[cur] = pnt++;
            cur = nxt[cur];
        }
        clen[cycles++] = pnt;
    }
    scanf("%s", A); alen = strlen(A);
    scanf("%s", B); blen = strlen(B);
    for (int i = 0; i < alen; i++)
        S[slen++] = head[A[i] - 'a'];
    for (int i = 0; i < blen; i++)
        S[slen++] = head[B[i] - 'a'];
    int l = -1, r = -1;
    for (int i = 1; i < slen; i++) {
        if (i <= r) Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < slen && S[Z[i]] == S[i + Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
        if (i >= alen)
            res[i - alen] = Z[i] >= alen? '1': '0';
    }
    prepareFirst(V1);
    prepareSecond(V2, A, alen);
    base tmp(0, 0);
    for (int i = 0; i < alen; i++)
        tmp += V1[alen - 1 - i] * V2[i];
    ld need = tmp.real();
    prepareSecond(V2, B, blen);
    multiply(V1, V2, V3);
    for (int i = 0; i + alen <= blen; i++)
        if (fabs(V3[alen - 1 + i].real() - need) >= eps)
            res[i] = '0';
    res[blen - alen + 1] = '\0';
    printf("%s\n", res);
    return 0;
}