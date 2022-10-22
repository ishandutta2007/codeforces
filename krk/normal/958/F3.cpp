#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef complex<double> base;
typedef pair <int, int> ii;
typedef long long ll;
 
const double PI = acos(-1.0l);
const int mod = 1009;
const int Maxn = 200005;
const int Maxs = 524288;
const int Maxm = 20;
 
struct node {
    vector <int> seq;
    node() { seq.clear(); }
};

int rev[Maxm][Maxs];
int n, m, k;
int freq[Maxn];
node my[Maxn];
priority_queue <ii> Q;
 
void fft (vector<base> & a, int log_n, bool invert) {
    int n = (int) a.size();
 
    for (int i=0; i<n; ++i)
        if (i < rev[log_n][i])
            swap (a[i], a[rev[log_n][i]]);
 
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
 
void multiply (const node &a, const node &b, node &res) {
    vector <base> fa(a.seq.begin(), a.seq.end());
    vector <base> fb(b.seq.begin(), b.seq.end());
    size_t n = 1, log_n = 0;
    while (n < max (fa.size(), fb.size()))  { n <<= 1; log_n++; }
    n <<= 1; log_n++;
    fa.resize(n);
    fb.resize(n);
    fft(fa, log_n, false);
    fft(fb, log_n, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, log_n, true);
    res.seq.resize(n);
    for (int i = 0; i < n; i++)
        res.seq[i] = ll(fa[i].real() + 0.5) % mod;
    while (res.seq.size() > k + 1 || (!res.seq.empty() && res.seq.back() == 0))
        res.seq.pop_back();
}

void calc_rev (int n, int log_n) {
    for (int i=0; i<n; ++i) {
        rev[log_n][i] = 0;
        for (int j=0; j<log_n; ++j)
            if (i & (1<<j))
                rev[log_n][i] |= 1<<(log_n-1-j);
    }
}
 
int main()
{
    for (int i = 0; i < Maxm; i++)
        calc_rev(1 << i, i);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    for (int i = 1; i <= m; i++) if (freq[i]) {
        my[i].seq.resize(freq[i] + 1, 1);
        Q.push(ii(-my[i].seq.size(), i));
    }
    int global;
    while (!Q.empty()) {
        int v = Q.top().second; Q.pop();
        if (Q.empty()) { global = v; break; }
        int u = Q.top().second; Q.pop();
        multiply(my[v], my[u], my[v]);
        Q.push(ii(-my[v].seq.size(), v));
    }
    printf("%d\n", my[global].seq[k]);
    return 0;
}