
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        priority_queue<pii> Q;
        rep(i, 2, n + 1) {
            Q.push({i, i});
        }
        vector<pii> ops;
        while(sz(Q) > 1) {
            auto x = Q.top(); Q.pop();
            auto y = Q.top(); Q.pop();
            if(x.first > 2 && 1LL * (y.first - 1) * (y.first - 1) < x.first) {
                ops.push_back({x.second, y.second});
                Q.push(y);
                Q.push({(x.first + y.first - 1) / y.first, x.second});
            }else {
                ops.push_back({y.second, x.second});
                Q.push(x);
            }
        }

        cout << sz(ops) << '\n';
        for(auto &pa : ops) {
            cout << pa.first << ' ' << pa.second << '\n';
        }
    }
}