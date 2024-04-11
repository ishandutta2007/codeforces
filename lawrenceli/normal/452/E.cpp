#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<19;
const int MAXLG = 20;
const int MOD = 1e9 + 7;

int n, m;
string str[3];
char s[MAXN];
int ind[MAXN], pre[MAXN];
int grp[MAXLG][2*MAXN], sa[MAXN], sa2[MAXN], gs[MAXN], cnt;

bool cmp(int a, int b) { return s[a] < s[b]; }

void initsa() {
    memset(grp, -1, sizeof(grp));
    for (int i=0; i<n; i++) sa[i] = i;
    sort(sa, sa+n, cmp);
    gs[0] = 0;
    for (int i=0; i<n; i++) {
        if (i && s[sa[i]] != s[sa[i-1]])
            gs[++cnt] = i;
        grp[0][sa[i]] = cnt;
    }
    for (int k=1; k<MAXLG; k++) {
        for (int i=0; i<n; i++)
            if (sa[i]+(1<<k-1) >= n)
                sa2[gs[grp[k-1][sa[i]]]++] = sa[i];
        for (int i=0; i<n; i++)
            if (sa[i] >= 1<<k-1)
                sa2[gs[grp[k-1][sa[i]-(1<<k-1)]]++] = sa[i]-(1<<k-1);
        for (int i=0; i<n; i++) sa[i] = sa2[i];
        cnt = 0;
        gs[0] = 0;
        for (int i=0; i<n; i++) {
            if (i && (grp[k-1][sa[i]] != grp[k-1][sa[i-1]] || grp[k-1][sa[i]+(1<<k-1)] != grp[k-1][sa[i-1]+(1<<k-1)]))
                gs[++cnt] = i;
            grp[k][sa[i]] = cnt;
        }
    }
}

int lcp(int a, int b) {
    int ret = 0;
    for (int k=MAXLG-1; k>=0; k--)
        if (a<n && b<n && grp[k][a] == grp[k][b])
            ret += 1<<k, a += 1<<k, b += 1<<k;
    return ret;
}

int ans, res[MAXN];
pii sor[MAXN];

struct data {
    int ar[3];
    int p;
} par[MAXN];

int val(data d) {
    return ll(d.ar[0])*d.ar[1]%MOD*d.ar[2]%MOD;
}

data getpar(int a) { return par[a].p == a ? par[a] : par[a] = getpar(par[a].p); }
void merge(int a, int b) {
    a = getpar(a).p;
    b = getpar(b).p;
    ans = (ans-val(par[a])+MOD)%MOD;
    ans = (ans-val(par[b])+MOD)%MOD;
    par[a].p = b;
    rep(i, 3) par[b].ar[i] += par[a].ar[i];
    ans = (ans+val(par[b]))%MOD;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    rep(i, 3) {
        cin >> str[i];
        rep(j, str[i].length())
            s[n] = str[i][j], ind[n] = i, n++;
        ind[n] = -1, s[n] = 200+i, n++;
    }

    m = min(str[0].length(), min(str[1].length(), str[2].length()));

    rep(i, n) {
        if (ind[i] >= 0)
            par[i].ar[ind[i]]++;
        par[i].p = i;
    }

    initsa();
    rep(i, n-1) {
        pre[i] = lcp(sa[i], sa[i+1]);
        sor[i] = pii(pre[i], i);
    }
/*
    rep(i, n) cout << sa[i] << ' ';
    cout << endl;

    rep(i, n) {
        rep(j, 3) cout << par[i].ar[j] << ' ';
        cout << endl;
    }

    rep(i, n-1) cout << pre[i] << ' ';
    cout << endl;
    cout << endl;
*/
    sort(sor, sor+n-1);
    int p = n-2;
    for (int l=m; l>0; l--) {
        while (p && sor[p].fi >= l)
            merge(sa[sor[p].se], sa[sor[p].se+1]), p--;
        res[l] = ans;
        /*
        rep(i, n) {
            rep(j, 3) cout << par[i].ar[j] << ' ';
            cout << endl;
        }
        cout << endl;
        */
    }

    for (int i=1; i<=m; i++)
        cout << res[i] << ' ';
    return 0;
}