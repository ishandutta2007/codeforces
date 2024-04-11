#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print(vector<ll>& v) {
    for (auto i : v) cout << i << ' '; cout << endl;
}

struct FFT {
    static const ll mod = (119 << 23) + 1, root = 3;

    static ll exp(ll b, ll e) {
        if (!e) return 1;
        if (e & 1) return b * exp(b, e - 1) % mod;
        ll res = exp(b, e >> 1);
        return res * res % mod;
    }

    static ll fix(ll a) {
        while (a >= mod) a -= mod;
        return a;
    }

    static void fft(vector<ll>& v, const vector<ll>& w, bool inv = false) {
        //reorder v for fast processing
        int n = v.size();
        for (int i = 1, j = 0; i < n; i++) {
            int r = n >> 1;
            for (; j >= r; r >>= 1) j &= ~r;
            j |= r;
            if (i < j) swap(v[i], v[j]);
        }

        for (int len = 1, skip = n >> 1; len < n; len <<= 1, skip >>= 1) {
            for (int i = 0; i < n; i += (len << 1)) {
                for (int j = 0, k = 0; j < len; j++, k += skip) {
                    ll a = v[i + j];
                    ll b = (inv ? w[n - k] : w[k]) * v[i + j + len] % mod;
                    v[i + j] = fix(a + b);
                    v[i + j + len] = fix(a + mod - b);
                }
            }
        }

        if (inv) {
            ll ninv = exp(n, mod - 2);
            for (int i = 0; i < n; i++) v[i] = v[i] * ninv % mod;
        }
    }


    /*
    //fft on v[l, r)
    static void fft(vector<ll>& v, ll w) {
        if (v.size() == 1) return;

        int n2 = v.size() / 2;

        vector<ll> v1 (n2), v2 (n2);
        for (int i = 0; i < n2; i++) {
            v1[i] = v[2 * i];
            v2[i] = v[2 * i + 1];
        }
        fft(v1, w * w % mod);
        fft(v2, w * w % mod);

        ll wc = 1;
        for (int i = 0; i < n2; i++) {
            ll a = v1[i], b = wc * v2[i] % mod;
            v[i] = (a + b) % mod;
            v[i + n2] = (a + mod - b) % mod;
            wc = wc * w % mod;
        }
    }
    */

    static vector<ll>& conv(vector<ll>& a, vector<ll>& b) {
        int n = 1;
        while (n < a.size() && n < b.size()) n <<= 1;
        n <<= 1;
        a.resize(n, 0);
        b.resize(n, 0);

        ll w = exp(root, (mod - 1) / n);
        vector<ll> vw (n + 1);
        vw[0] = vw[n] = 1;
        for (int i = 1; i < n; i++) vw[i] = vw[i - 1] * w % mod;
        fft(a, vw);
        fft(b, vw);

        for (int i = 0; i < n; i++) a[i] = (a[i] * b[i]) % mod;

        fft(a, vw, 1);

        return a;
    }

};

const int maxn = 500100;

int n;
char s[maxn];
bool bad[maxn];
int ans[maxn], anssze;

void go() {
    scanf("%d\n%s\n", &n, s);
    assert(n == strlen(s));
    for (int i = 0; i < n; i++) bad[i] = 0;
    
    vector<ll> v1 (n, 0), v2 (n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') v1[i] = 1;
        else if (s[i] == 'K') v2[i] = 1;
    }

    reverse(v2.begin(), v2.end());

    vector<ll> v = FFT::conv(v1, v2);

    for (int k = 1; k < n; k++)
        if (v[n - 1 + k] || v[n - 1 - k])
            bad[k] = 1;

    anssze = 0;
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = i; j < n; j += i)
            if (bad[j]) {
                good = false;
                break;
            }
        if (good) ans[anssze++] = i;
    }

    printf("%d\n", anssze);
    for (int i = 0; i < anssze; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) go();
}