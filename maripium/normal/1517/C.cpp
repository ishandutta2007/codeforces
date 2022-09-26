#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    vector<vector<int>> ans(N);
    for (int i = 0; i < N; ++i) {
        ans[i].resize(i+1, -1);
    }

    for (int i = 0; i < N; ++i) {
        int p; cin >> p;

        int z = p;
        int x = i, y = i;
        while (p) {
            if (ans[x][y] == -1) {
                ans[x][y] = z;
                p--;
            }
            if (y > 0 && ans[x][y-1] == -1) {
                --y;
            } else if (x+1 < N) {
                x++;
            } else {
                x = i, y = i;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j : ans[i]) cout << j << ' ';
        cout << '\n';
    }
}