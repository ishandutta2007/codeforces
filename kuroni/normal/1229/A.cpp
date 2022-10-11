#include <bits/stdc++.h>
using namespace std;

const int N = 7005;

int n, u;
long long ans = 0, a[N];
vector<long long> ve;
map<long long, bool> ma;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (ma[a[i]]) {
            ve.push_back(a[i]);
        } else {
            ma[a[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> u;
        bool chk = false;
        for (long long &v : ve) {
            if ((a[i] & v) == a[i]) {
                chk = true;
            }
        }
        if (chk) {
            ans += u;
        }
    }
    cout << ans;
}