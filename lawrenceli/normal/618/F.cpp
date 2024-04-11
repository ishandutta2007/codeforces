#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 1000100;

int n;
int a[maxn], b[maxn];
ll p[maxn], q[maxn];
int ind[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        q[i + 1] = q[i] + b[i];
    }

    bool swp = 0;
    if (p[n] > q[n]) {
        swap(a, b);
        swap(p, q);
        swp = 1;
    }

    memset(ind, -1, sizeof(ind));
    for (int i = 0; i <= n; i++) {
        int k = lower_bound(q, q + n + 1, p[i]) - q;
        assert(q[k] - p[i] < n);
        if (ind[q[k] - p[i]] != -1) {
            int j = ind[q[k] - p[i]];
            int l = lower_bound(q, q + n + 1, p[j]) - q;

            if (swp) {
                swap(i, k);
                swap(j, l);
            }

            cout << i - j << '\n';
            for (int x = j + 1; x <= i; x++)
                cout << x << ' ';
            cout << '\n';

            cout << k - l << '\n';
            for (int x = l + 1; x <= k; x++)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }
        
        ind[q[k] - p[i]] = i;
    }
}