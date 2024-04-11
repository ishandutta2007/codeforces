#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x, x--;

    vector<int> sp(n);
    const int B = sqrt(n);

    for (int i = 0; i < n; i++) {
        sp[i] = i;
        for (int j = 0; j < B; j++)
            sp[i] = p[sp[i]];
    }

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[p[i]] = i;

    vector<int> way1, way2;
    way1.reserve(B);
    way2.reserve(B);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int first, second;
            cin >> first >> second;
            first--, second--;
            int to_first = p[first], to_second = p[second];

            parent[p[first]] = second;
            parent[p[second]] = first;
            swap(p[first], p[second]);

            way1.clear();
            for (int i = 0, pos = to_first; i < B; i++, pos = p[pos])
                way1.push_back(pos);

            way2.clear();
            for (int i = 0, pos = to_second; i < B; i++, pos = p[pos])
                way2.push_back(pos);

            for (int ln = 0, pos = first; ln < B; ln++, pos = parent[pos])
                sp[pos] = way2[B - 1 - ln];

            for (int ln = 0, pos = second; ln < B; ln++, pos = parent[pos])
                sp[pos] = way1[B - 1 - ln];
        } else if (type == 2) {
            int pos, k;
            cin >> pos >> k;
            pos--;

            for (; k >= B; k -= B)
                pos = sp[pos];

            while (k--)
                pos = p[pos];

            cout << pos + 1 << '\n';
        } else {
            assert(false);
        }
    }
}