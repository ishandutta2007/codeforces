#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e3 + 100;
int delta[maxN];
int t[maxN], l[maxN], r[maxN];
bool ok[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> l[i] >> r[i];
        if (t[i] == 1) {
            delta[l[i]] += 1;
            delta[r[i]] -= 1;
        }
    }
    for (int i = 1; i < n; i++) {
        delta[i] += delta[i - 1];
        if (delta[i] > 0) ok[i] = true;
        else ok[i] = false;
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 0) {
            bool has = false;
            for (int j = l[i]; j < r[i]; j++) {
                if (!ok[j]) {
                    has = true;
                    break;
                }
            }
            if (!has) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << "YES" << '\n';
    int prv = 100000;
    cout << prv << " ";
    for (int j = 2; j <= n; j++) {
        if (ok[j - 1]) prv++;
        else prv--;
        cout << prv << " ";
    }
    return 0;
}