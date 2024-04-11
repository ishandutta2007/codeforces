#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
int a[maxN];
int n;
vector < int > vals[maxN];
int ans[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = n - x;
        vals[a[i]].push_back(i);
    }
    int clr = 0;
    for (int i = 1; i <= n; i++) {
        if (vals[i].size() % i != 0) {
            cout << "Impossible";
            return 0;
        }
        for (int j = 0; j < vals[i].size(); j++) {
            if (j % i == 0) {
                clr++;
            }
            ans[vals[i][j]] = clr;
        }
    }
    cout << "Possible" << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}