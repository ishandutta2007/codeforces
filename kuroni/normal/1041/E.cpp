#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, x, y, cnt[N];
bool chk[N];
vector<pair<int, int>> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        if (y != n) {
            return cout << "NO", 0;
        } else {
            cnt[x]++;
        }
    }
    int pt = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        int p = n;
        while (--cnt[i]) {
            while (pt < i && chk[pt]) {
                pt++;
            }
            if (pt >= i || chk[i]) {
                return cout << "NO", 0;
            }
            chk[pt] = true;
            ans.push_back({p, pt});
            p = pt;
        }
        if (chk[i]) {
            return cout << "NO", 0;
        }
        chk[i] = true;
        ans.push_back({p, i});
    }
    cout << "YES\n";
    for (pair<int, int> &v : ans) {
        cout << v.first << " " << v.second << '\n';
    }
}