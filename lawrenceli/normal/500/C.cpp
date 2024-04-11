#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
const int MAXM = 1005;

int n, m, w[MAXN], b[MAXM], occ[MAXN], ord[MAXN];

bool cmp(int i1, int i2) { return occ[i1] < occ[i2]; }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> w[i];
    for (int i=0; i<n; i++) occ[i] = m, ord[i] = i;
    for (int i=0; i<m; i++) {
        cin >> b[i]; b[i]--;
        if (occ[b[i]] == m) occ[b[i]] = i;
    }

    sort(ord, ord+n, cmp);
    int ans = 0;
    for (int i=0; i<m; i++) {
        int ind=-1;
        for (int j=0; j<n; j++)
            if (ord[j] == b[i]) {
                ind = j;
                break;
            } else ans += w[ord[j]];
        int num = ord[ind];
        for (int j=ind-1; j>=0; j--) ord[j+1] = ord[j];
        ord[0] = num;
    }

    cout << ans << '\n';
    return 0;
}