
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for each shortcut, we have a number b_i that gives it as an array
// after each query we want to know:
// sum_i max(b_i - a_i, 0).

const int N = 2e5 + 5;
int n, q, s, t, u;
ll a[N], b[N], bit[N];
map<pair<int, int>, int> m;

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= n) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> q;
    while(q--) {
        cin >> s >> t >> u;
        if(m[{s, t}] != 0) {
            int u2 = m[{s, t}];
            m.erase({s, t});
            if(b[u2] > 0) {
                b[u2]--;
            }else {
                add(u2, -1);
            }
        }
        if(u != 0) {
            m[{s, t}] = u;
            if(getSum(u) - getSum(u - 1) >= a[u]) {
                b[u]++;
            }else {
                add(u, 1);
            }
        }
        cout << (sum - getSum(n)) << endl;
    }
}