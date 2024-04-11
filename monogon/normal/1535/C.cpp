
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

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    int j = 0;
    int cnt[2] = {0, 0};
    rep(i, 0, n) {
        while(j < n && (s[j] != '0' || cnt[!(j % 2)] == 0) && (s[j] != '1' || cnt[j % 2] == 0)) {
            if(s[j] == '0') cnt[j % 2]++;
            if(s[j] == '1') cnt[!(j % 2)]++;
            j++;
        }
        ans += j - i;
        if(s[i] == '0') cnt[i % 2]--;
        if(s[i] == '1') cnt[!(i % 2)]--;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}