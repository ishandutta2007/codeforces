#include <bits/stdc++.h>
using namespace std;

int n, k, u, x;
long long msk = 0, ful;
vector<long long> ve = {0};

void sort_mask(vector<long long> &ve, long long msk) {
    vector<long long> add = {0};
    for (int i = 0; i < n; i++) {
        if (msk >> i & 1) {
            add.push_back(add.back() ^ (1LL << i));
        }
    }
    for (long long &x : ve) {
        int cnt = __builtin_popcountll(msk & x);
        x &= (ful ^ msk);
        x ^= add[cnt];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k; ful = (1LL << n) - 1;
    if (n == 1) {
        return cout << "ACCEPTED", 0;
    }
    while (k--) {
        cin >> u;
        long long cur = 0;
        while (u--) {
            cin >> x;
            cur ^= 1LL << (n - x);
        }
        int sz = ve.size();
        for (long long lef = (ful ^ msk) & cur; lef > 0; lef -= lef & -lef) {
            for (int i = 0; i < sz; i++) {
                ve.push_back(ve[i] | lef);
            }
        }
        sort_mask(ve, cur);
        msk |= cur;
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    if (msk != ful || ve.size() != n + 1) {
        return cout << "REJECTED", 0;
    }
    for (int i = 0; i <= n; i++) {
        if (ve[i] != (1LL << i) - 1) {
            return cout << "REJECTED", 0;
        }
    }
    cout << "ACCEPTED";
}