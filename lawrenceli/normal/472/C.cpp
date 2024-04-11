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
typedef pair<string, pii> psp;

const int MAXN = 200100;

int n, p[MAXN], bit[MAXN], ord[MAXN][2];
psp ar[MAXN];

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] += v;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        string a, b;
        cin >> a >> b;
        if (a>b) swap(a, b);
        ar[2*i] = psp(a, pii(i, 0));
        ar[2*i+1] = psp(b, pii(i, 1));
    }
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }

    sort(ar, ar+2*n);
    rep(i, 2*n)
        ord[ar[i].se.fi][ar[i].se.se] = i;

    rep(i, n) {
        int j = p[i];
        if (query(ord[j][0]) == i) update(ord[j][0], 1);
        else if (query(ord[j][1]) == i) update(ord[j][1], 1);
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}