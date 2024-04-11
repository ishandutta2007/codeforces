#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int mx = 2 * *max_element(all(a));
    int answer = 0;

    for (int bit = 0; (1 << bit) < mx; bit++) {
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] ^ (a[i] & ~(1 << bit));

        array<vector<int>, 2> first;
        first.fill(vector<int>(mx, n));

        for (int i = 0; i < n;)
            if (a[i] >> bit & 1) {
                int j = i + 1;
                while (j < n && (a[j] >> bit & 1))
                    j++;

                for (int k = i; k <= j; k++) {
                    answer = max(answer, k - first[k & 1][pref[k]]);
                    if (first[k & 1][pref[k]] == n)
                        first[k & 1][pref[k]] = k;
                }

                for (int k = i; k <= j; k++)
                    first[k & 1][pref[k]] = n;

                i = j;
            } else
                i++;

        for (auto &x : a)
            x &= ~(1 << bit);
    }

    cout << answer << '\n';
}