
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, d;
ll x;
set<ll> sx, sy;
priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sx.insert(x);
        Q.emplace(0, x);
    }
    ll sum = 0;
    while(Q.size() && (int) sy.size() < m) {
        tie(d, x) = Q.top();
        Q.pop();
        if(sy.count(x)) continue;
        if(sx.count(x) == 0) {
            sy.insert(x);
            sum += d;
        }
        if(d == 0 || sx.count(x) == 0) {
            Q.emplace(d + 1, x + 1);
            Q.emplace(d + 1, x - 1);
        }
    }
    cout << sum << endl;
    for(int x : sy) {
        cout << x << " ";
    }
    cout << endl;
}