#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <deque>

using namespace std;

typedef long long ll;

struct line {
    ll m, b;
    line() {}
    line(ll m, ll b) : m(m), b(b) {}
    ll val(ll x) { return m*x + b; }
};

const int MAXN = 100100;

int n;
ll a[MAXN], b[MAXN], dp[MAXN];
deque<line> dq;

bool del(line l3) {
    line l1 = dq[dq.size()-2], l2 = dq[dq.size()-1];
    return double(l3.b - l1.b) / (l3.m - l1.m) > double(l2.b - l1.b) / (l2.m - l1.m);
    //return (l3.b - l1.b) * (l2.m - l1.m) > (l2.b - l1.b) * (l3.m - l1.m);
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    dq.push_back(line(b[0], 0));
    for (int i=1; i<n; i++) {
        while (dq.size() >= 2 && dq[1].val(a[i]) <= dq[0].val(a[i])) dq.pop_front();
        dp[i] = dq[0].val(a[i]);

        line l = line(b[i], dp[i]);
        while (dq.size() >= 2 && del(l)) dq.pop_back();
        dq.push_back(l);
    }

    cout << dp[n-1] << endl;
    return 0;
}