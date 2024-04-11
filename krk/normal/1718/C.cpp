#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;
const int Maxm = 250;

struct segtree {
    int n;
    vector <ll> st;
    segtree(int gn = 0) {
        n = gn;
        int m = 1;
        while (m <= 4 * n) m *= 2;
        st.resize(m);
    }
    void Union(int v) { st[v] = max(st[2 * v], st[2 * v + 1]); }
    void Create(int v, int l, int r, const vector <ll> &seq) {
        if (l == r) st[v] = seq[l];
        else {
            int m = l + r >> 1;
            Create(2 * v, l, m, seq);
            Create(2 * v + 1, m + 1, r, seq);
            Union(v);
        }
    }
    void Create(const vector <ll> &seq) { Create(1, 0, n - 1, seq); }
    void Update(int v, int l, int r, int ind, int val) {
        if (l == r) st[v] += val;
        else {
            int m = l + r >> 1;
            if (ind <= m) Update(2 * v, l, m, ind, val);
            else Update(2 * v + 1, m + 1, r, ind, val);
            Union(v);
        }
    }
    void Update(int ind, int val) { Update(1, 0, n - 1, ind, val); }
    ll Get() { return st[1]; }
};

int T;
int n, q;
int a[Maxn];
int slen;
ll mx;
int D[Maxm];
vector <ll> B[Maxm];
segtree S[Maxm];

void Update(int ind, int val)
{
    if (val == 0) return;
    a[ind] += val;
    mx = 0;
    for (int i = 0; i < slen; i++) {
        S[i].Update(ind % D[i], val);
        mx = max(mx, ll(D[i]) * S[i].Get());
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        slen = 0;
        mx = 0;
        for (int i = n - 1; i > 0; i--) if (n % i == 0) {
            bool ok = true;
            for (int j = 0; j < slen; j++)
                if (D[j] % i == 0) {
                    ok = false;
                    break;
                }
            if (!ok) continue;
            D[slen] = i;
            B[slen].clear();
            B[slen].resize(i, 0);
            for (int j = 0; j < n; j++)
                B[slen][j % i] += a[j];
            S[slen] = segtree(i);
            S[slen].Create(B[slen]);
            mx = max(mx, ll(i) * S[slen].Get());
            slen++;
        }
        printf("%I64d\n", mx);
        for (int i = 0; i < q; i++) {
            int ind, val; scanf("%d %d", &ind, &val);
            ind--;
            Update(ind, val - a[ind]);
            printf("%I64d\n", mx);
        }
    }
    return 0;
}