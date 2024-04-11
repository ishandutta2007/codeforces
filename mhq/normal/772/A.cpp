#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
int a[maxN], b[maxN], p;
int n;
const ld eps = 1e-9;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> p;
    vector < int > ord;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [](int x, int y) {
        return 1LL * b[x] * a[y] < 1LL * b[y] * a[x];
    });
    ll sumA = 0;
    ll sumB = 0;
    for (int i = 0; i < ord.size(); i++) {
        sumA += a[ord[i]];
        sumB += b[ord[i]];
        if (p >= sumA) continue;
        ll stX = sumB;
        ll stY = sumA - p;
        if (i == ord.size() - 1 || (1LL * stX * a[ord[i + 1]] <= 1LL * stY * b[ord[i + 1]])) {
            cout << fixed << setprecision(10) << max(1.0 * b[ord[i]] / a[ord[i]], 1.0 * stX / stY);
            return 0;
        }
    }
    cout << -1;
};