#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;

const double PI = acos(-1.0l);
 
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
        double ang = 2*PI/len * (invert ? -1 : 1);
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

void Fix(vector <int> &V)
{
    while (V.size() > 1 && V.back() == 0) V.pop_back();
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
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
        res[i] = int (fa[i].real() + 0.5) > 0;
    Fix(res);
}

void safeMultiply(const vector <int> &a, const vector <int> &b, vector <int> &res)
{
    vector <int> A = a;
    vector <int> B = b;
    multiply(A, B, res);
}

int n, k;
vector <int> seq(1001, 0);

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        seq[a] = 1;
    }
    vector <int> res(1, 1);
    while (k) {
        if (k & 1) safeMultiply(res, seq, res);
        k >>= 1; safeMultiply(seq, seq, seq);
    }
    vector <int> ans;
    for (int i = 1; i < res.size(); i++) if (res[i] > 0)
        ans.push_back(i);
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i + 1 < ans.size()? ' ': '\n');
    return 0;
}