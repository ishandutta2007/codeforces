#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxK = 5e6 + 10;
int cnt[maxK];
const int maxN = 2e5 + 10;
int a[maxN];
int lst[maxK];
pair<int,int> t[maxK];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int x = -1;
    int y = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < maxK; i++) {
        if (cnt[i] >= 4) {
            vector<int> inds;
            for (int z = 1; z <= n; z++) {
                if (a[z] == i && inds.size() < 4) inds.emplace_back(z);
            }
            cout << "YES\n";
            cout << inds[0] << " " << inds[1] << " " << inds[2] << " " << inds[3] << '\n';
            return 0;
        }
        if (cnt[i] >= 2) {
            if (x == -1) x = i;
            else if (y == -1) y = i;
        }
    }
    if (x != -1 && y != -1) {
        vector<int> ind1, ind2;
        for (int i = 1; i <= n; i++) {
            if (a[i] == x && ind1.size() < 2) ind1.emplace_back(i);
            if (a[i] == y && ind2.size() < 2) ind2.emplace_back(i);
        }
        cout << "YES\n";
        cout << ind1[0] << " " << ind2[0] << " " << ind1[1] << " " << ind2[1];
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int c = a[i] + a[j];
            if (t[c] != make_pair(0, 0)) {
                if (a[t[c].first] == a[i] || a[t[c].second] == a[i]) continue;
                cout << "YES\n";
                cout << i << " " << j << " " << t[c].first << " " << t[c].second;
                return 0;
            }
            t[c] = make_pair(i, j);
        }
    }
    cout << "NO\n";
    return 0;
}