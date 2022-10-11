#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

inline bool in(int l, int r, int x) {
    return l <= x && x <= r;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;
    vec<int> b(m);
    for (auto &x : b)
        cin >> x;
    if (n < m) {
        swap(n, m);
        swap(a, b);
    }
    int mx = 2 * max(n, m) + 1;
    vec<int> where(mx);
    for (int i = 0; i < n; i++)
        where[a[i]] = i;

    vec<vec<int>> cycles;
    vec<int> index(n);
    vec<char> used(n);
    vec<int> num(n);
    vec<map<int, int>> cnt;

    for (int i = 0; i < n; i++)
        if (!used[i]) {
            cycles.push_back({});
            cnt.push_back(map<int, int>());
            for (int j = i; !used[j]; j = (j + m) % n) {
                used[j] = 1;
                index[j] = (len(cycles.back()) ? index[cycles.back().back()] + 1 : 0);
                num[j] = len(cycles) - 1;
                cnt.back()[a[j]]++;
                cycles.back().push_back(j);
            }
        }

    ll one = 0;
    for (int i = 0; i < m; i++) {
        one += len(cycles[num[i]]);
        if (cnt[num[i]].find(b[i]) != cnt[num[i]].end())
            one -= cnt[num[i]][b[i]];
    }
    ll lcm = ll(n) * m / gcd(n, m);
    ll need = (k - 1) / one;
    k -= need * one;
    ll st = need * lcm;

    ll l = 0, r = lcm;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll left = k;
        for (int i = 0; i < m; i++)
            if (i < mid) {
                int from = index[i];
                int delta = (mid - (i + 1)) / m;
                int to = from + delta;
                int cur = delta + 1;
                if (where[b[i]] != -1 && num[where[b[i]]] == num[i])
                    if (in(from, to, index[where[b[i]]]) || (to >= len(cycles[num[i]]) && in(0, to - len(cycles[num[i]]), index[where[b[i]]])))
                        cur--;
                left -= cur;
                if (left <= 0)
                    break;
            }
        if (left <= 0)
            r = mid;
        else
            l = mid;
    }
    cout << st + r << '\n';
}