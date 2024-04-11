#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1005;
int ans[maxN][maxN];
int sz = 0;
int n;
const int INF = (int)1e9 + 100;
void ask(vector < int > f) {
    if (f.empty()) {
        for (int i = 1; i <= n; i++) {
            ans[sz][i] = INF;
        }
        sz++;
        return;
    }
    cout << f.size() << endl;
    for (int v : f) cout << v << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cin >> ans[sz][i];
    sz++;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int f = 0; f < 2; f++) {
        for (int bit = 0; bit < 10; bit++) {
            vector < int > who;
            for (int i = 1; i <= n; i++) {
                if (((i >> bit) & 1) == f) who.push_back(i);
            }
            ask(who);
        }
    }
    vector < int > vals;
    for (int i = 1; i <= n; i++) {
        int mn = INF;
        for (int bit = 0; bit < 10; bit++) {
            int pos = bit + 10 * (((i >> bit) & 1) ^ 1);
            mn = min(mn, ans[pos][i]);
        }
        vals.push_back(mn);
    }
    cout << -1 << endl;
    for (int v : vals) cout << v << " ";
    cout << endl;
    return 0;
}