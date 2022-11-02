#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, pii> data;

const int MAXN = 100100;

int k, n, m, a[MAXN], num[MAXN];
pii as[MAXN];
vector<pii> add[MAXN];
vector<ll> pre[MAXN], best[MAXN];
vector<bool> uas[MAXN];
vector<data> vsort;

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> k >> n >> m;
    for (int i=0; i<k; i++) {
        cin >> a[i];
        as[i] = pii(-1, -1);
    }
    for (int i=0; i<n; i++) {
        int t, j, b;
        cin >> t >> j >> b;
        j--;
        if (t == 1) as[j] = max(as[j], pii(b, i));
        else if (t == 2) add[j].push_back(pii(b, i));
        else vsort.push_back(data(b, pii(-1, i)));
    }

    for (int i=0; i<k; i++) {
        sort(add[i].begin(), add[i].end(), greater<pii>());
        pre[i].resize(add[i].size()+1, 0);
        for (int j=0; j<add[i].size(); j++)
            pre[i][j+1] = pre[i][j] + add[i][j].fi;

        best[i].resize(pre[i].size()+1);
        uas[i].resize(pre[i].size()+1, 0);
        for (int j=0; j<pre[i].size(); j++) {
            best[i][j] = pre[i][j] + a[i];
            if (j>0 && as[i].fi != -1 && pre[i][j-1] + as[i].fi > best[i][j])
                uas[i][j] = 1, best[i][j] = pre[i][j-1] + as[i].fi;

            if (j>0) vsort.push_back(data(ld(best[i][j])/best[i][j-1], pii(i, j)));
        }

        if (as[i].fi > a[i]) {
            int sze = pre[i].size();
            uas[i][sze] = 1;
            best[i][sze] = pre[i][sze-1] + as[i].fi;
            vsort.push_back(data(ld(best[i][sze])/best[i][sze-1], pii(i, sze)));
        }
    }

    sort(vsort.begin(), vsort.end(), greater<data>());
    vector<int> ans, ans2;

    m = min(m, int(vsort.size()));
    for (int i=0; i<m; i++) {
        int x = vsort[i].se.fi, y = vsort[i].se.se;
        if (x == -1) ans2.push_back(y);
        else {
            assert(num[x] < y);
            num[x] = y;
        }
    }

    for (int i=0; i<k; i++) {
        if (uas[i][num[i]]) ans.push_back(as[i].se), num[i]--;
        for (int j=0; j<num[i]; j++)
            ans.push_back(add[i][j].se);
    }
    for (int i : ans2) ans.push_back(i);

    assert(ans.size() == m);

    cout << ans.size() << '\n';
    for (int i : ans) cout << i+1 << ' ';
}