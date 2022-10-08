
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

const int N = 1e6 + 5;
int n, q, a, k, bit[N];

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
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> a;
        add(a, 1);
    }
    rep(i, 0, q) {
        cin >> k;
        if(k < 0) {
            k = -k - 1;
            int L = 0, R = n;
            while(L < R) {
                int m = (L + R) / 2;
                if(getSum(m) <= k) {
                    L = m + 1;
                }else {
                    R = m;
                }
            }
            add(L, -1);
        }else {
            add(k, 1);
        }
    }
    rep(i, 1, n + 1) {
        if(bit[i] > 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
}