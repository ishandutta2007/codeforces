
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int m, n, k, t, a[N];

struct trap {
    int l, r, d;
} tr[N];

int pass(int A) {
    int prevr = -1;
    int cost = n + 1;
    for(int i = 0; i < k; i++) {
        if(tr[i].d <= A) continue;
        if(prevr < tr[i].l) {
            cost += 2 * (tr[i].r - tr[i].l + 1);
            prevr = tr[i].r;
        }else if(prevr < tr[i].r) {
            cost += 2 * (tr[i].r - prevr);
            prevr = tr[i].r;
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> k >> t;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> tr[i].l >> tr[i].r >> tr[i].d;
    }
    sort(a, a + m);
    sort(tr, tr + k, [](trap a, trap b) { return a.l < b.l; });
    int L = 0, R = m;
    while(L < R) {
        int mid = (L + R) / 2;
        if(pass(a[mid]) <= t) {
            R = mid;
        }else {
            L = mid + 1;
        }
    }
    cout << m - L << endl;
}