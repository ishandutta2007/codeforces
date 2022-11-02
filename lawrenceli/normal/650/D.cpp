#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 400100;

int n, m, h[maxn];
int qa[maxn], qb[maxn];
vector<pii> qry[maxn];

int ans[maxn];

int dl[maxn], dr[maxn];
vector<int> nums[maxn];

bool bot[maxn]; //bottleneck

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) {
        cin >> qa[i] >> qb[i];
        qa[i]--;
        qry[qa[i]].push_back(pii(qb[i], i));
    }

    for (int i = 1; i < maxn; i++) dl[i] = 2e9;
    dr[0] = -2e9;
    for (int i = 0; i < n; i++) {
        for (pii p : qry[i]) {
            int x = lower_bound(dl, dl + n, p.A) - dl;
            ans[p.B] = x;
            //if (p.B == 0) cout << x << ' ' << p.A << endl;
        }

        int p = lower_bound(dl, dl + n, h[i]) - dl;
        dl[p] = h[i];
        nums[p].push_back(i);
    }

    for (int i = n - 1; i >= 0; i--) {
        for (pii p : qry[i]) {
            int x = lower_bound(dr, dr + n, -p.A) - dr;
            ans[p.B] += x - 1;
            //if (p.B == 0) cout << x << endl;
        }

        int p = lower_bound(dr, dr + n, -h[i]) - dr;
        dr[p] = -h[i];
    }

    int maxl = 0;
    for (int i = 0; i <= n; i++)
        if (dl[i] < 2e9)
            maxl = i;

    vector<int> v = nums[maxl];
    for (int i = maxl - 1; i >= 0; i--) {
        if (v.size() == 1) bot[v[0]] = 1;
        if (i == 0) break;

        int p = 0;
        vector<int> w;
        for (int j : nums[i]) {
            while (p < v.size() && v[p] <= j) p++;
            if (p < v.size() && h[v[p]] > h[j])
                w.push_back(j);
        }

        v = w;
    }

    for (int i = 0; i < m; i++) {
        int x = bot[qa[i]] ? maxl - 1 : maxl;
        //if (i == 0) cout << "ANS: " << ans[i] << endl;
        cout << max(x, ans[i]) << '\n';
    }
}