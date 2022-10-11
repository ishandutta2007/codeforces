#include <bits/stdc++.h>
using namespace std;

const int S = 1E6;

int n, u;
bool chk[S + 1];
vector<int> ve, pr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        chk[u] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= S / 2; i++) {
        int l = i, r = S + 1 - l;
        if (chk[l] ^ chk[r]) {
            ve.push_back({chk[l] ? r : l});
        } else if (chk[l] && chk[r]) {
            cnt++;
        } else {
            pr.push_back(l);
        }
    }
    while (cnt--) {
        int l = pr.back(), r = S + 1 - l;
        pr.pop_back();
        ve.push_back(l); ve.push_back(r);
    }
    cout << ve.size() << '\n';
    for (int v : ve) {
        cout << v << ' ';
    }
}