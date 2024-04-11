#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int x[maxN];
int y[maxN];
int n;
bool on_line(int i, int j, int k) {
    ll a = y[j] - y[i];
    ll b = x[i] - x[j];
    ll c = -a * x[i] - b * y[i];
    return ((a * x[k] + b * y[k] + c) == 0);
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    if (n <= 4) {
        cout << "YES";
        exit(0);
    }
    for (int iter = 0; iter < 100; iter++) {
        int cnt[3] = {0, 0, 0};
        cnt[1] = (rand() % n) + 1;
        cnt[2] = (rand() % n + 1);
        while (cnt[2] == cnt[1]) cnt[2] = rand() % n + 1;
        vector < int > left;
        for (int i = 1; i <= n; i++) {
            if (!on_line(cnt[1], cnt[2], i)) left.push_back(i);
        }
        if (left.size() <= 2) {
            cout << "YES";
            exit(0);
        }
        bool ok = true;
        for (int i = 2; i < left.size(); i++) {
            if (!on_line(left[0], left[1], left[i])) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        cout << "YES";
        exit(0);
    }
    cout << "NO";
    return 0;
}