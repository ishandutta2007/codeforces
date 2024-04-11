
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    ll len2() const {
        return x * x + y * y;
    }
    pt normalize() {
        ll g = gcd(x, y);
        return pt(x / g, y / g);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    map<pair<ll, ll>, int> cnt;
    map<ll, set<pair<ll, ll>>> ma;
    int n = 0;
    while(q--) {
        int t; pt p;
        cin >> t >> p.x >> p.y;
        ll len = p.len2();
        if(t == 1) {
            n++;
            for(auto &pa : ma[len]) {
                pt p2 = (p + pt(pa.first, pa.second)).normalize();
                cnt[{p2.x, p2.y}] += 2;
            }
            ma[len].insert({p.x, p.y});
            p = p.normalize();
            cnt[{p.x, p.y}]++;
        }else if(t == 2) {
            n--;
            ma[len].erase({p.x, p.y});
            for(auto &pa : ma[len]) {
                pt p2 = (p + pt(pa.first, pa.second)).normalize();
                cnt[{p2.x, p2.y}] -= 2;
            }
            p = p.normalize();
            cnt[{p.x, p.y}]--;
        }else if(t == 3) {
            p = p.normalize();
            cout << (n - cnt[{p.x, p.y}]) << '\n';
        }
    }
}