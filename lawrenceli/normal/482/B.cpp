#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
const int MAXB = 30;

typedef pair<int, int> pii;

int n, m, l[MAXN], r[MAXN], q[MAXN], ans[MAXN][MAXB], pre[MAXN][MAXB];
vector<pii> qry[MAXB];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        for (int j=0; j<MAXB; j++)
            if (q[i]&1<<j) {
                qry[j].push_back(pii(l[i], 1));
                qry[j].push_back(pii(r[i], -1));
            }
    }

    for (int i=0; i<MAXB; i++) {
        sort(qry[i].begin(), qry[i].end());
        int p = 0, cnt = 0;
        for (int j=0; j<n; j++) {
            while (p<qry[i].size() && qry[i][p].first == j)
                cnt += qry[i][p++].second;
            if (cnt) ans[j][i] = 1;
            pre[j+1][i] = pre[j][i] + ans[j][i];
        }
    }

    for (int i=0; i<m; i++)
        for (int j=0; j<MAXB; j++)
            if (!(q[i]&1<<j)) {
                if (pre[r[i]][j]-pre[l[i]][j] == r[i]-l[i]) {
                    cout << "NO";
                    return 0;
                }
            }

    cout << "YES\n";
    for (int i=0; i<n; i++) {
        int x = 0;
        for (int j=0; j<MAXB; j++)
            x += (1<<j)*ans[i][j];
        cout << x << ' ';
    }
}