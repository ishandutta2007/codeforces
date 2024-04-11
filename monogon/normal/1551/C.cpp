
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// 2 * cnt(a) - length > 0

void solve() {
    int n;
    cin >> n;
    vector<array<int, 6>> ve;
    rep(i, 0, n) {
        string s;
        cin >> s;
        array<int, 6> cnt = {0};
        for(char c : s) {
            cnt[c - 'a']++;
            cnt[5]++;
        }
        ve.push_back(cnt);
    }
    int best = 0;
    rep(c, 0, 5) {
        sort(all(ve), [&](auto a, auto b) {
            return 2 * a[c] - a[5] > 2 * b[c] - b[5];
        });
        int sum = 0;
        rep(i, 0, sz(ve)) {
            sum += 2 * ve[i][c] - ve[i][5];
            if(sum > 0) best = max(best, i + 1);
        }
    }
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}