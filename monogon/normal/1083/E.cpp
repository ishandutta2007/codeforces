
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n;
ll dp[N];

struct rect {
    ll x, y, a;
} r[N];

struct line {
    ll A, B, p;
    bool operator<(const ll x) const {
        return p < x;
    }
    ll eval(const ll x) const {
        return A * x + B;
    }
};

vector<line> lines;

ll query(ll x) {
    if(lines.empty()) return LLONG_MIN;
    return lower_bound(lines.begin(), lines.end(), x)->eval(x);
}

ll floordiv(const ll a, const ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}
void insert(ll A, ll B) {
    line l = {A, B, LLONG_MAX};
    while(lines.size() >= 2) {
        int i = (int) lines.size() - 1;
        lines[i].p = floordiv(lines[i].B - l.B, l.A - lines[i].A);
        if(lines[i].p <= lines[i - 1].p) lines.pop_back();
        else break;
    }
    if(lines.size() == 1) {
        int i = (int) lines.size() - 1;
        lines[i].p = floordiv(lines[i].B - l.B, l.A - lines[i].A);
    }
    lines.push_back(l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> r[i].x >> r[i].y >> r[i].a;
    }
    sort(r, r + n, [](rect a, rect b) { return a.x < b.x; });

    ll m = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        dp[i] = r[i].x * r[i].y - r[i].a;
        dp[i] = max(dp[i], dp[i] + query(-r[i].y));
        insert(r[i].x, dp[i]);
        m = max(m, dp[i]);
    }
    cout << m << endl;
}