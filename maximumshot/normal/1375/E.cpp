#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
        p[i] = i;
    }

    sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    for (int i = 0; i < n; i++)
        q[p[i]] = i;
    p = q;

//    for (int x : p)
//        cout << x << " ";
//    cout << "\n";

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    vector<pii> res;

    auto _swap = [&](int i, int j) {
        swap(p[i], p[j]);
        pos[p[i]] = i;
        pos[p[j]] = j;
        res.emplace_back(min(i, j), max(i, j));
    };

    for (int i = n - 1; i >= 0; i--) {
        for (int x = p[i] + 1; x <= i; x++) {
            _swap(pos[x], i);
        }
    }

    cout << (int) res.size() << "\n";

    for (auto x : res) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }

//    for (int x : p)
//        cout << x << " ";
//    cout << "\n";

    return 0;
}