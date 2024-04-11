
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
    int sum = n;
    vi cnt(2 * n, 0);
    for(char c : s) {
        if(c == '0') {
            cnt[sum - 1]++;
            sum--;
        }else {
            cnt[sum]++;
            sum++;
        }
    }
    string ans;
    function<void(int)> dfs = [&](int x) {
        if(x > 0) {
            while(cnt[x - 1] > 0) {
                cnt[x - 1]--;
                dfs(x - 1);
                ans.push_back('0');
            }
        }
        if(x < 2 * n) {
            while(cnt[x] > 0) {
                cnt[x]--;
                dfs(x + 1);
                ans.push_back('1');
            }
        }
    };
    dfs(n);
    reverse(all(ans));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}