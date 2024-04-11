#include <bits/stdc++.h>
using namespace std;

const int N = 1005, PR[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int t, n, u, ans[N];
vector<int> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        ve.clear();
        for (int i = 1; i <= n; i++) {
            cin >> u;
            for (int j = 0; j < 11; j++) {
                if (u % PR[j] == 0) {
                    ans[i] = j;
                    ve.push_back(j);
                    break;
                }
            }
        }
        sort(ve.begin(), ve.end());
        ve.erase(unique(ve.begin(), ve.end()), ve.end());
        cout << ve.size() << '\n';
        for (int i = 1; i <= n; i++) {
            cout << distance(ve.begin(), upper_bound(ve.begin(), ve.end(), ans[i])) << " ";
        }
        cout << '\n';
    }
}