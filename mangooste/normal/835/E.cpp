#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    auto guess = [&](int length) {
        return length % 2 == 0 ? (x ^ y) : y;
    };

    auto query = [&](const vector<int> &v) {
        cout << "? " << len(v);
        for (auto pos : v)
            cout << ' ' << pos + 1;

        cout << endl;

        int x;
        cin >> x;
        return x == guess(len(v));
    };

    auto find = [&](const vector<int> &v) {
        int l = -1, r = len(v) - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            (query(vector(v.begin(), v.begin() + mid + 1)) ? r : l) = mid;
        }
        return v[r];
    };

    int lg = __lg(n) + 1, mask = 0;
    array<int, 2> answer{-1, -1};

    for (int bit = 0; bit < lg; bit++) {
        array<vector<int>, 2> groups;
        for (int i = 0; i < n; i++)
            groups[i >> bit & 1].push_back(i);

        if (len(groups[0]) > len(groups[1]))
            swap(groups[0], groups[1]);

        if (groups[0].empty())
            continue;

        if (query(groups[0])) {
            mask ^= 1 << bit;
            if (answer[0] == -1)
                answer[0] = find(groups[0]);
        }
    }

    assert(answer[0] != -1);
    answer[1] = answer[0] ^ mask;

    if (answer[0] > answer[1])
        swap(answer[0], answer[1]);

    cout << "! " << answer[0] + 1 << ' ' << answer[1] + 1 << endl;
}