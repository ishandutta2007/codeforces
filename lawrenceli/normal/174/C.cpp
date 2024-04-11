#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXLG = 17;

int n, ar[MAXN], tab[MAXLG][MAXN];
vector<pii> ans;

int rmq(int l, int r) {
    int ret = l;
    for (int k=MAXLG-1; k>=0; k--) {
        if (l+(1<<k)<=r) {
            if (ar[ret] > ar[tab[k][l]]) ret = tab[k][l];
            l += 1<<k;
        }
    }
    return ret;
}

void dfs(int l, int r, int sub) {
    if (l == r) return;
    int m = rmq(l, r);
    for (int i=0; i<ar[m]-sub; i++)
        ans.push_back(pii(l, r));
    dfs(l, m, ar[m]);
    dfs(m+1, r, ar[m]);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        tab[0][i] = i;
    }
    for (int k=0; k<MAXLG-1; k++)
        for (int i=0; i<n; i++) {
            tab[k+1][i] = tab[k][i];
            if (i+(1<<k)<n && ar[tab[k][i+(1<<k)]] < ar[tab[k][i]])
                tab[k+1][i] = tab[k][i+(1<<k)];
        }

    for (int l=0, r; l<n; l=r+1) {
        r = l;
        while (r<n && ar[r] != 0) r++;
        dfs(l, r, 0);
    }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i].fi+1 << ' ' << ans[i].se << '\n';
    return 0;
}