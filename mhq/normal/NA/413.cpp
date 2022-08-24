#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
const int maxN = (int)1e5 + 10;
int a[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin.tie(nullptr);
    cin >> n >> m;
    vector < int > all_a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all_a.push_back(x);
    }
    vector < int > all_b;
    for (int i = 1; i <= m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 != 1) continue;
        all_b.push_back(x2);
    }
    all_a.push_back(0);
    all_a.push_back((int)1e9);
    sort(all_a.begin(), all_a.end());
    sort(all_b.begin(), all_b.end());
    int mn = n + m;
    for (int i = 0; i + 1 < all_a.size(); i++) {
        int t = lower_bound(all_b.begin(), all_b.end(), all_a[i + 1]) - all_b.begin();
       // cout << i << "  "<< t << " " << all_b.size() << " " << all_a[i + 1] << endl;
        mn = min(mn, (int)all_b.size() - t + i);
    }
    cout << mn;
    return 0;
}