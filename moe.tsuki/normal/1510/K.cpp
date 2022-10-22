#include <bits/stdc++.h>
#define all(v) begin(v),end(v)
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> p[i];
    }
    const auto f1 = [n](vector<int> v) {
        for (int i = 0; i < n * 2; i += 2)
            swap(v[i], v[i + 1]);
        return v;
    };
    const auto f2 = [n](vector<int> v) {
        for (int i = 0; i < n; i++)
            swap(v[i], v[i + n]);
        return v;
    };
    auto q = p;
    for (int iter = 0; iter < n * 5; iter++) {
        if (is_sorted(all(p)) || is_sorted(all(q))) {
            cout << iter << '\n';
            return 0;
        }
        if (iter % 2 == 0) {
            p = f1(p);
            q = f2(q);
        } else {
            p = f2(p);
            q = f1(q);
        }
    }
    cout << -1 << '\n';
    return 0;
}