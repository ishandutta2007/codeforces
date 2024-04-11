
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 2e5 + 5;
int n;
struct pt {
    ll x, y;
} p[N];

map<ll, vi> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> p[i].x >> p[i].y;
        ma[max(p[i].x, p[i].y)].push_back(i);
    }
    ll xx = 0, yy = 0, xx2 = 0, yy2 = 0;
    ll d1 = 0, d2 = 0;
    for(auto &pa : ma) {
        vi ve = pa.se;
        auto cmp = [&](int i, int j) {
            return p[i].y - p[i].x < p[j].y - p[j].x;
        };
        int i = *min_element(ve.begin(), ve.end(), cmp);
        int j = *max_element(ve.begin(), ve.end(), cmp);
        ll d = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
        ll newd1 = d + min(d1 + abs(xx - p[j].x) + abs(yy - p[j].y), d2 + abs(xx2 - p[j].x) + abs(yy2 - p[j].y));
        ll newd2 = d + min(d1 + abs(xx - p[i].x) + abs(yy - p[i].y), d2 + abs(xx2 - p[i].x) + abs(yy2 - p[i].y));
        d1 = newd1;
        d2 = newd2;
        xx = p[i].x;
        yy = p[i].y;
        xx2 = p[j].x;
        yy2 = p[j].y;
    }
    cout << min(d1, d2) << '\n';
}