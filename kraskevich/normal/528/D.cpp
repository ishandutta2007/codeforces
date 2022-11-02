#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;

bool bad[N];

typedef complex<double> Data;
typedef Data base;

const double PI = acos(-1);
    
void merge(vector<Data>& b, int low, int high) {
    int n = high - low;
    base cur(1), mul(cos(2. * PI / n), sin(2. * PI / n));
    for (int i = low; i < low + n / 2; i++) {
        Data temp = b[i + n / 2] * cur;
        b[i + n / 2] = b[i] - temp;
        b[i] = b[i] + temp;
        cur = cur * mul;
    }
}
    
void do_fft(vector<Data>& b) {
    int n = b.size();
    int hi = 0;
    while ((1 << hi) < n)
        hi++;
    hi--;
    vector<int> p(n);
    for (int i = 0; i < n; i++) 
        for (int b = hi; b >= 0; b--)
            if (i & (1 << b))
                p[i] |= (1 << (hi - b));
    vector<Data> buf(n);
    for (int i = 0; i < n; i++)
        buf[i] = b[p[i]];
    copy(buf.begin(), buf.end(), b.begin());
    for (int h = 2; h <= n; h *= 2)
        for (int i = 0; i < n; i += h)
            merge(b, i, i + h);
}

void do_reverse_fft(vector<Data>& b) {
    do_fft(b);
    int n = b.size();
    reverse(b.begin() + 1, b.end());
    for (int i = 0; i < n; i++)
        b[i] /= n;
}

const int POLYNOM_SIZE = (1 << 19);

void solve(string s, string t, int k, char c) {
    set<int> pos;
    int slen = s.length();
    int tlen = t.length();
    for (int i = 0; i < slen; i++)
        if (s[i] == c)
            pos.insert(i);
    vector<Data> a(POLYNOM_SIZE);
    for (int i = 0; i < slen; i++) {
        auto it = pos.lower_bound(i);
        bool ok = false;
        if (it != pos.end() && *it - i <= k)
            ok = true;
        if (it != pos.begin()) {
            it--;
            if (i - *it <= k)
                ok = true;
        }
        if (!ok)
            a[i] = 1.0;
    }
    vector<Data> b(POLYNOM_SIZE);
    for (int i = 0; i < tlen; i++)
        if (t[i] == c)
            b[tlen - i] = 1.0;
    do_fft(a);
    do_fft(b);
    for (int i = 0; i < a.size(); i++)
        a[i] *= b[i];
    do_reverse_fft(a);
    for (int p = 0; p < slen; p++)
        if (a[p + tlen].real() > 0.5)
            bad[p] = true; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    string t;
    cin >> s >> t;
    solve(s, t, k, 'A');
    solve(s, t, k, 'C');
    solve(s, t, k, 'G');
    solve(s, t, k, 'T');
    int res = 0;
    for (int i = 0; i <= s.length() - t.length(); i++)
        if (!bad[i])
            res++;
    cout << res << endl;
    return 0;
}