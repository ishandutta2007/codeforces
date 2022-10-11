#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int N = 5e6 + 2;

inline bool ok(pr<int> a, int x) {
    return a.first != x && a.second != x;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<pr<int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(all(arr));
    vec<int> a(n), id(n);
    for (int i = 0; i < n; i++)
        tie(a[i], id[i]) = arr[i];

    pr<int> good{-1, -1};
    for (int i = n - 2; i >= 0; i--)
        if (a[i] == a[i + 1]) {
            if (good.first == -1)
                good = {id[i], id[i + 1]};
            else if (good.first != id[i + 1]) {
                cout << "Yes\n";
                cout << id[i] + 1 << ' ' << good.first + 1 << ' ' << id[i + 1] + 1 << ' ' << good.second + 1 << '\n';
                return 0;
            }
        }

    n = min(n, 5000);
    vec<pr<int>> can(N, {-1, -1});
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            pr<int> &now = can[a[i] + a[j]];
            if (now.first == -1)
                now = {id[i], id[j]};
            else if (ok(now, id[i]) && ok(now, id[j])) {
                cout << "Yes\n";
                cout << now.first + 1 << ' ' << now.second + 1 << ' ' << id[i] + 1 << ' ' << id[j] + 1 << '\n';
                return 0;
            }
        }
    cout << "No\n";
}