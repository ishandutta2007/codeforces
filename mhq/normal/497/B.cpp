#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = (int)1e5 + 10;
int a[maxN];
int pref[2][maxN];
vector < pair < int, int > > ans;
void solve(int plays) {
    int l = 1;
    int num_1 = 0;
    int num_2 = 0;
    while (true) {
        if (l == n + 1) break;
        if (pref[0][n] - pref[0][l - 1] < plays) return ;
        int ind1 = lower_bound(pref[0], pref[0] + n + 1, pref[0][l - 1] + plays) - pref[0];
        if (pref[1][n] - pref[1][l - 1] < plays) {
            num_1++;
            l = ind1 + 1;
            continue;
        }
        int ind2 = lower_bound(pref[1], pref[1] + n + 1, pref[1][l - 1] + plays) - pref[1];
        if (ind1 < ind2) {
            num_1++;
            l = ind1 + 1;
        }
        else {
            num_2++;
            l = ind2 + 1;
        }
    }
    if (num_1 > num_2) ans.push_back(make_pair(num_1, plays));
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]--;
    }
    if (a[n] == 1) {
        for (int i = 1; i <= n; i++) {
            a[i] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            pref[j][i] = pref[j][i - 1];
            pref[j][i] += (a[i] == j);
        }
    }
    for (int num = 1; num <= n; num++) {
        solve(num);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto t : ans) {
        cout << t.first << " " << t.second << '\n';
    }
    return 0;
}