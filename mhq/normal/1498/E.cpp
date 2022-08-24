#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
int k[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, pair<int,int>>> g;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (k[i] <= k[j]) {
                g.emplace_back(k[j] - k[i], make_pair(i, j));
            }
        }
    }

    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    for (auto& it : g) {
        cout << "? " << it.second.second + 1 << " " << it.second.first + 1 << endl;
        string resp;
        cin >> resp;
        if (resp == "Yes") {
            cout << "! " << it.second.first + 1 << " " << it.second.second + 1 << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}