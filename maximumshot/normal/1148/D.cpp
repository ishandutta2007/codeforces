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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<pii, int>> a, b;

    for (int i = 0; i < n; i++) {
        pii p;
        cin >> p.first >> p.second;
        if (p.first < p.second) {
            a.push_back({p, i});
        } else {
            b.push_back({p, i});
        }
    }

    sort(a.begin(), a.end(), [&](pair<pii, int> p1, pair<pii, int> p2){
        return p1.first.first > p2.first.first;
    });

    sort(b.begin(), b.end(), [&](pair<pii, int> p1, pair<pii, int> p2){
        return p1.first.first < p2.first.first;
    });

    if ((int)a.size() < (int)b.size()) {
        swap(a, b);
    }

    cout << (int)a.size() << "\n";
    for (auto i : a) {
        cout << i.second + 1 << " ";
    }
    cout << "\n";

    return 0;
}