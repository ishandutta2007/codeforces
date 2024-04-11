// I hate interactive problems!!!!

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;

    auto query = [&](int a, int b, int c) {
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int res;
        cin >> res;
        return res ^ 1;
    };

    array<vector<int>, 2> groups;
    for (int i = 0; i < n; i += 3)
        groups[query(i, i + 1, i + 2)].push_back(i);

    assert(!groups[0].empty() && !groups[1].empty());
    int first = groups[1][0], second = groups[0][0];
    pair<int, int> bad{-1, -1}, good{-1, -1};

    for (int i = first; i < first + 3 && bad.first == -1; i++)
        for (int j = i + 1; j < first + 3; j++)
            if (i == first + 1 || (query(i, j, second) == 1 && query(i, j, second + 1) == 1)) {
                bad = {i, j};
                break;
            }

    assert(bad.first != -1);
    for (int i = second; i < second + 3 && good.first == -1; i++)
        for (int j = i + 1; j < second + 3; j++)
            if (i == second + 1 || query(i, j, bad.first) == 0){ 
                good = {i, j};
                break;
            }

    assert(good.first != -1);
    vector<int> answer;
    answer.push_back(bad.first);
    answer.push_back(bad.second);

    for (int i = first; i < first + 3; i++)
        if (i != bad.first && i != bad.second && query(i, bad.first, good.first) == 1)
            answer.push_back(i);

    groups[1].erase(groups[1].begin());
    for (int i = second; i < second + 3; i++)
        if (i != good.first && i != good.second && query(i, bad.first, good.first) == 1)
            answer.push_back(i);

    groups[0].erase(groups[0].begin());
    for (int j : {0, 1}) {
        int another = j == 0 ? bad.first : good.first;
        for (auto i : groups[j])
            if (query(another, i, i + 1) == j) {
                if (j == 1) {
                    answer.push_back(i);
                    answer.push_back(i + 1);
                }
                if (query(i + 2, bad.first, good.first) == 1)
                    answer.push_back(i + 2);
            } else if (query(another, i, i + 2) == j) {
                if (j == 0) {
                    answer.push_back(i + 1);
                } else {
                    answer.push_back(i);
                    answer.push_back(i + 2);
                }
            } else {
                if (j == 0) {
                    answer.push_back(i);
                } else {
                    answer.push_back(i + 1);
                    answer.push_back(i + 2);
                }
            }
    }

    cout << "! " << len(answer) << ' ';
    for (int i = 0; i < len(answer); i++)
        cout << answer[i] + 1 << " \n"[i == len(answer) - 1];

    cout << flush;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}