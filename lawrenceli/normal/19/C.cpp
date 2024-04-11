#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<17;
const int MAXLG = 18;
const int MULT = 1e9 + 7;

int n, ar[MAXN], del;
map<int, vector<int> > mp;
vector<pii> vrep;

int grp[MAXLG][2*MAXN], sa[MAXN], sa2[MAXN], gs[MAXN], cnt;

bool cmp1(int a, int b) { return ar[a] < ar[b]; }

void initsa() {
    memset(grp, -1, sizeof(grp));
    for (int i=0; i<n; i++) sa[i] = i;
    sort(sa, sa+n, cmp1);
    gs[0] = 0;
    for (int i=0; i<n; i++) {
        if (i && ar[sa[i]] != ar[sa[i-1]])
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
    /*
    for (int k=0; k<MAXLG; k++) {
        for (int i=0; i<n; i++)
            cout << grp[k][i] << ' ';
        cout << endl;
    }
    */
}

int lcp(int a, int b) {
    int ret = 0;
    for (int k=MAXLG-1; k>=0; k--)
        if (a<n && b<n && grp[k][a] == grp[k][b])
            ret += 1<<k, a += 1<<k, b += 1<<k;
    return ret;
}

bool cmp(pii p1, pii p2) {
    return p1.se-p1.fi != p2.se-p2.fi ? p1.se-p1.fi < p2.se-p2.fi : p1.fi < p2.fi;
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        mp[ar[i]].push_back(i);
    }

    initsa();

    for (int i=0; i<n; i++)
        for (int k=0; k<mp[ar[i]].size(); k++) {
            int j = mp[ar[i]][k];
            if (j <= i || 2*j-i > n) continue;
            if (lcp(i, j) >= j-i)
                vrep.push_back(pii(i, j));
        }

    sort(vrep.begin(), vrep.end(), cmp);
    for (int i=0; i<vrep.size(); i++) {
        int l = vrep[i].fi, r = vrep[i].se;
        //cout << l << ' ' << r << endl;
        if (l < del) continue;
        del = r;
    }

    cout << n-del << '\n';
    for (int i=del; i<n; i++)
        cout << ar[i] << ' ';
    return 0;
}