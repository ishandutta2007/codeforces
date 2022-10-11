#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1005;

int n, x[N], y[N];
vector<int> ve[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    while (true) {
        for (int i = 0; i < 4; i++) {
            ve[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            ve[((x[i] & 1) << 1) ^ (y[i] & 1)].push_back(i);
        }
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            cnt += (!ve[i].empty());
        }
        if (cnt >= 3) {
            cout << ve[0].size() + ve[3].size() << '\n';
            for (int &v : ve[0]) {
                cout << v << " ";
            }
            for (int &v : ve[3]) {
                cout << v << " ";
            }
            return 0;
        } else if (cnt >= 2) {
            for (int i = 0; i < 4; i++) {
                if (!ve[i].empty()) {
                    cout << ve[i].size() << '\n';
                    for (int &v : ve[i]) {
                        cout << v << " ";
                    }
                    return 0;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                (x[i] -= (x[i] & 1)) /= 2;
                (y[i] -= (y[i] & 1)) /= 2;
            }
        }
    }
}