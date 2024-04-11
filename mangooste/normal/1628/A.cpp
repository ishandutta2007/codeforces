#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> occ(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        occ[x].push_back(i);
    }

    for (auto &v : occ)
        reverse(all(v));

    vector<int> answer;
    for (int i = 0; i < n;) {
        int mex = 0, new_i = 0;
        while (true) {
            while (!occ[mex].empty() && occ[mex].back() < i)
                occ[mex].pop_back();

            if (occ[mex].empty())
                break;

            new_i = max(new_i, occ[mex].back());
            occ[mex].pop_back();
            mex++;
        }

        if (mex == 0) {
            for (; i < n; i++)
                answer.push_back(0);

            break;
        }

        answer.push_back(mex);
        i = new_i + 1;
    }

    cout << len(answer) << '\n';
    for (int i = 0; i < len(answer); i++)
        cout << answer[i] << " \n"[i == len(answer) - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}