#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int x[nax];
void solve() {
    cin >> n >> k;
    vector <int> neg;
    vector <int> pos;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i];
        if (x[i] < 0) neg.push_back(-x[i]);
        else pos.push_back(x[i]);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    int64_t sum = 0;
    int mx = 0;
    while (pos.size() >= k) {
        sum += pos.back() * 2;
        mx = max(mx, pos.back());
        for (int i = 0 ; i < k ; ++ i) pos.pop_back();
    }
    if (!pos.empty()) {
        sum += pos.back() * 2;
        mx = max(mx, pos.back());
    }

    while (neg.size() >= k) {
        sum += neg.back() * 2;
        mx = max(mx, neg.back());
        for (int i = 0 ; i < k ; ++ i) neg.pop_back();
    }
    if (!neg.empty()) {
        sum += neg.back() * 2;
        mx = max(mx, neg.back());
    }
    cout << sum - mx<< '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/**
    Final exam tomorrow?
    Who cared.
*/