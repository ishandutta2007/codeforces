
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

// 01, 10
ll x, y;

struct lmao {
    ll cnt[2];
    ll cost;
    queue<bool> Q;
    lmao() {
        cnt[0] = cnt[1] = cost = 0;
    }
    void push(bool b) {
        Q.push(b);
        if(b) cost += x * cnt[!b];
        else cost += y * cnt[!b];
        cnt[b]++;
    }
    void pop() {
        assert(!Q.empty());
        bool b = Q.front(); Q.pop();
        if(b) cost -= y * cnt[!b];
        else cost -= x * cnt[!b];
        cnt[b]--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s >> x >> y;
    int n = s.length();
    if(x > y) {
        for(char &c : s) {
            if(c == '0') c = '1';
            else if(c == '1') c = '0';
        }
        swap(x, y);
    }
    lmao left, right;
    for(char c : s) {
        right.push(c == '?' || c == '1');
    }
    ll ans = LLONG_MAX;
    auto upd = [&]() {
        ans = min(ans, left.cost + right.cost + x * left.cnt[0] * right.cnt[1] + y * left.cnt[1] * right.cnt[0]);
    };
    upd();
    rep(i, 0, n) {
        right.pop();
        left.push(s[i] == '1');
        upd();
    }
    cout << ans << '\n';
}