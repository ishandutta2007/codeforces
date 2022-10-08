
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll a[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        v.emplace_back(a[i], -t[i]);
    }
    sort(v.begin(), v.end());
    ll p = -1;
    priority_queue<pair<ll, int>> Q;
    int i = 0;
    ll ans = 0;
    while(i < (int) v.size()) {
        auto [pos, tmp] = v[i];
        if(!Q.empty() && (pos > p + 1 || (pos == p + 1 && Q.top().first > -tmp))) {
            auto [x, j] = Q.top(); Q.pop();
            ans += x * (++p - j);
        }else if(p == pos) {
            Q.emplace(-tmp, pos);
            i++;
        }else {
            p = pos;
            i++;
        }
    }
    while(!Q.empty()) {
        auto [x, j] = Q.top(); Q.pop();
        ans += x * (++p - j);
    }
    cout << ans << endl;
}