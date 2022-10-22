#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 600005;
const int Maxm = 4194304;
const int mod = 1000000007;

struct node {
    int val, A, B, len;
    node(): val(0), A(0), B(0), len(0) {}
};

int ipw2[Maxn];
int n;
int p[Maxn];
int q;
int qi[Maxn], qx[Maxn];
vector <int> un;
int cnt[Maxn];
node st[Maxm];
int psum[Maxn], pval[Maxn];

void Union(int v)
{
    int lc = 2 * v, rc = 2 * v + 1;
    st[v].val = (ll(st[lc].val) + ll(st[rc].val) + ll(st[lc].A) * st[rc].B) % mod;
    st[v].A = (ll(st[lc].A) * ipw2[st[rc].len] + ll(st[rc].A)) % mod;
    st[v].B = (ll(st[lc].B) + ll(st[rc].B) * ipw2[st[lc].len]) % mod;
    st[v].len = st[lc].len + st[rc].len;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].val = ll(pval[cnt[l]]) * un[l] % mod * un[l] % mod;
        st[v].A = st[v].B = ll(psum[cnt[l]]) * un[l] % mod;
        st[v].len = cnt[l];
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int x)
{
    if (l == r) {
        st[v].val = ll(pval[cnt[l]]) * un[l] % mod * un[l] % mod;
        st[v].A = st[v].B = ll(psum[cnt[l]]) * un[l] % mod;
        st[v].len = cnt[l];
    } else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        Union(v);
    }
}

int main()
{
    ipw2[0] = 1;
    ipw2[1] = (mod + 1) / 2;
    for (int i = 2; i < Maxn; i++)
        ipw2[i] = ll(ipw2[i - 1]) * ipw2[1] % mod;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        un.push_back(p[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qi[i], &qx[i]);
        un.push_back(qx[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    psum[1] = ipw2[1]; pval[1] = 0;
    for (int i = 2; i < Maxn; i++) {
        psum[i] = (ll(psum[i - 1] + 1) * ipw2[1]) % mod;
        pval[i] = (pval[i - 1] + ll(psum[i - 1]) * ipw2[1]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        p[i] = lower_bound(un.begin(), un.end(), p[i]) - un.begin();
        cnt[p[i]]++;
    }
    Create(1, 0, int(un.size()) - 1);
    printf("%d\n", st[1].val);
    for (int i = 1; i <= q; i++) {
        qx[i] = lower_bound(un.begin(), un.end(), qx[i]) - un.begin();
        int ind = qi[i];
        if (p[ind] != qx[i]) {
            cnt[p[ind]]--;
            Update(1, 0, int(un.size()) - 1, p[ind]);
            p[ind] = qx[i];
            cnt[p[ind]]++;
            Update(1, 0, int(un.size()) - 1, p[ind]);
        }
        printf("%d\n", st[1].val);
    }
    return 0;
}