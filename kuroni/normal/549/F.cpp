#include <bits/stdc++.h>
using namespace std;

const int N = 300005, K = 1E6 + 5;

int n, k, su[N], a[N], l[N], r[N];
long long ans;
vector<int> pos[K];

int get(vector<int> &pos, int l, int r) {
    return distance(lower_bound(pos.begin(), pos.end(), l),
                    upper_bound(pos.begin(), pos.end(), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    pos[su[0]].push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        su[i] = (su[i - 1] + a[i]) % k;
        pos[su[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;
        while (a[l[i]] < a[i] && l[i] > 0) {
            l[i] = l[l[i]];
        }
    }
    for (int i = n; i >= 1; i--) {
        r[i] = i + 1;
        while (a[r[i]] <= a[i] && r[i] <= n) {
            r[i] = r[r[i]];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i - l[i] < r[i] - i) {
            for (int j = l[i]; j < i; j++) {
                int tmp = (su[j] + a[i]) % k;
                ans += get(pos[tmp], i, r[i] - 1);
            }
        } else {
            for (int j = i; j < r[i]; j++) {
                int tmp = (((su[j] - a[i]) % k) + k) % k;
                ans += get(pos[tmp], l[i], i - 1);
            }
        }
    }
    cout << ans - n;
}