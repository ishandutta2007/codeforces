#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    vec<int> suf_max(n + 1, -n);
    auto can = [&](int val) {
        vec<int> bal(n);
        for (int i = 0; i < n; i++) {
            if (i)
                bal[i] = bal[i - 1];
            if (a[i] >= val)
                bal[i]++;
            else
                bal[i]--;
        }
        for (int i = n - 1; i >= 0; i--)
            suf_max[i] = max(suf_max[i + 1], bal[i]);
        for (int i = 0; i + k <= n; i++)
            if (suf_max[i + k - 1] > (i ? bal[i - 1] : 0))
                return true;
        return false;
    };

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}