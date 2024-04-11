#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
int root, root_1;
const int root_pw = 1 << 20;

int toPower(int a, int p, int mod)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int inverse(int x, int mod) { return toPower(x, mod - 2, mod); }

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = ll(fa[i]) * fb[i] % mod;
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i];
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

const int Maxn = 1000005;

int fac[Maxn];
int n;
vector <int> neigh[Maxn];
int C[Maxn];

void Traverse(int v, int p)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        C[v]++;
        Traverse(u, v);
    }
}

vector <int> Solve(int l, int r)
{
    if (l == r) {
        vector <int> res = {1};
        if (C[l]) res.push_back(C[l]);
        return res;
    } else {
        int m = l + r >> 1;
        return multiply(Solve(l, m), Solve(m + 1, r));
    }
}

int main()
{
    root = toPower(3, 952, mod);
    root_1 = inverse(root, mod);
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = ll(fac[i - 1]) * i % mod;
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 0);
    int res = 0;
    auto ans = Solve(1, n);
    for (int i = 0; i <= n && i < ans.size(); i++) {
        int cur = ll(fac[n - i]) * ans[i] % mod;
        if (i % 2) res = (res - cur + mod) % mod;
        else res = (res + cur) % mod;
    }
    printf("%d\n", res);
    return 0;
}