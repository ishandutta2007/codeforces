#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> data;

const int MAXN = 200100;

int n, m;
ll l[MAXN], r[MAXN];
data ar[MAXN];
pll use[MAXN];
set<pll> st;
int ans[MAXN];

bool cmp(data d1, data d2) {
    return d1.fi.se < d2.fi.se;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> l[i] >> r[i];
    for (int i=0; i+1<n; i++) {
        ar[i] = data(pll(l[i+1]-r[i], r[i+1]-l[i]), i);
    }

    for (int i=0; i<m; i++) {
        cin >> use[i].fi;
        use[i].se = i;
    }
    sort(use, use+m);
    sort(ar, ar+n-1, cmp);

    int p = 0;
    for (int i=0; i+1<n; i++) {
        while (p<m && use[p].fi <= ar[i].fi.se) {
            st.insert(use[p++]);
        }

        auto it = st.lower_bound(pll(ar[i].fi.fi, -1));
        if (it == st.end()) {
            cout << "No";
            return 0;
        } else ans[ar[i].se] = it->se+1, st.erase(it);
    }

    cout << "Yes\n";
    for (int i=0; i+1<n; i++) cout << ans[i] << ' ';
}