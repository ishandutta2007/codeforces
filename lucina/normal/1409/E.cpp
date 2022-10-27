#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
int x[nax];
int y[nax];


void solve() {
    cin >> n >> k;

    vector <int> com;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> x[i], com.push_back(x[i]);
    for (int i = 1 ; i <= n ; ++ i)
        cin >> y[i];
    com.push_back(INT_MAX);

    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    vector <int> s(com.size() + 1);

    auto where = [&](int x)->int {
        return lower_bound(com.begin(), com.end(), x) - com.begin();
    };

    for (int i = 1; i <= n ; ++ i) {
        s[where(x[i])] ++;
    }

    int m = com.size();
    vector <int> rev_sum(com.size() + 1);
    vector <int> most(com.size() + 1);


    for (int j = m - 1; j >= 0 ; -- j) {
        rev_sum[j] = rev_sum[j + 1] + s[j];
        int nxt = lower_bound(com.begin(), com.end(), com[j] + k) - com.begin();
        nxt += binary_search(com.begin(), com.end(), com[j] + k);
        int now = rev_sum[j] - rev_sum[nxt];
        most[j] = max(most[j + 1], now);
    }

    int ans = 0;

    for (int i = 0 ; i < m ; ++ i) {
        int nxt = lower_bound(com.begin(), com.end(), com[i] + k) - com.begin();
        nxt += binary_search(com.begin(), com.end(), com[i] + k);
        int now = rev_sum[i] - (nxt < int(rev_sum.size()) ? rev_sum[nxt] : 0);
        ans = max(ans, now + (nxt < int(rev_sum.size()) ? most[nxt] : 0));
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}
/*
    I have been too lazy, lately.
*/