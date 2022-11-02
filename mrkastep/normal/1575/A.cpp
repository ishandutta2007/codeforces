#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<pair<string, int>> v;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.emplace_back(s, i + 1);
    }

    auto cmp = [](const auto& lhs, const auto& rhs) {
        auto& l = lhs.first;
        auto& r = rhs.first;

        for (int i = 0; i < l.size(); ++i) {
            if (l[i] != r[i]) {
                return (l[i] < r[i]) ^ (i % 2 != 0);
            }
        }
    };

    sort(v.begin(), v.end(), cmp);

    for (const auto& [_, i] : v) {
        cout << i << ' ';
    }

    cout << endl;

    return 0;
}