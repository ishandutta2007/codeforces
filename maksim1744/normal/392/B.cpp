#include <bits/stdc++.h>

using namespace std;

#define ll   long long

array<array<ll, 3>, 3> t;
map<pair<pair<int, int>, ll>, ll> mem;

ll calc(int from, int to, int n) {
    auto p = make_pair(make_pair(from, to), n);
    if (mem.count(p))
        return mem[p];
    int mid = 3 - from - to;
    if (n == 1) {
        return mem[p] = min(t[from][mid] + t[mid][to], t[from][to]);
    }
    return mem[p] = min(calc(from, mid, n - 1) + t[from][to]  + calc(mid,   to, n - 1),
                        calc(from,  to, n - 1) + t[from][mid] + calc( to, from, n - 1) + t[mid][to] + calc(from, to, n - 1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> t[i][j];
        }
    }

    int n;
    cin >> n;

    cout << calc(0, 2, n) << '\n';

    return 0;
}