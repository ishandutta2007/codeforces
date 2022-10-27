#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
ll square(int x) {
    return x * (ll) x;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector< pair<ll, ll> > dist(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dist[i].first = square(x - x1) + square(y - y1);
        dist[i].second = square(x - x2) + square(y - y2);
    }
 
    sort(dist.begin(), dist.end());
    vector<ll> maxsuf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        maxsuf[i] = max(maxsuf[i + 1], dist[i].second);
    }
 
    ll result = min(dist[n - 1].first, maxsuf[0]);
    for (int i = 0; i < n; i++) {
        ll r1 = dist[i].first;
        ll r2 = maxsuf[i + 1];
        result = min(result, r1 + r2);
    }
 
    cout << result << '\n';
}