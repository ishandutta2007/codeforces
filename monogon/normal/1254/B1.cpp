
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];

ll getcost(const vector<int> &v, int x) {
    ll sum = 0;
    for(int y : v) sum += abs(y - x);
    return sum;
}

ll ternary(const vector<int> &v) {
    int l = v[0], r = v.back();
    while(r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = l + 2 * (r - l) / 3;
        ll c1 = getcost(v, m1);
        ll c2 = getcost(v, m2);
        if(c1 < c2) {
            r = m2 - 1;
        }else if(c1 > c2) {
            l = m1 + 1;
        }else {
            l = m1;
            r = m2;
        }
    }
    ll c = getcost(v, l);
    for(int i = l + 1; i <= r; i++) {
        c = min(c, getcost(v, i));
    }
    return c;
}

ll getcost(int k) {
    vector<int> v;
    ll cost = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]) {
            v.push_back(i);
        }
        if((int) v.size() == k) {
            cost += ternary(v);
            v.clear();
        }
    }
    return cost;
}

ll solve(int K) {
    ll mincost = getcost(K);
    for(int k = 2; k * k <= K; k++) {
        if(K % k == 0) {
            mincost = min(mincost, getcost(k));
            if(K / k > 1) {
                mincost = min(mincost, getcost(K / k));
            }
        }
    }
    return mincost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k += a[i];
    }
    if(k <= 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << solve(k) << endl;
}