#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int n;
int a[maxn][5];

int dot(int i, int j, int k) {
    int ret = 0;
    for (int b = 0; b < 5; b++)
        ret += (a[i][b] - a[j][b]) * (a[i][b] - a[k][b]);
    return ret;
}

bool good(int i) {
    for (int j = 0; j < n; j++)
        if (j != i)
            for (int k = 0; k < j; k++)
                if (k != i)
                    if (dot(i, j, k) > 0)
                        return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (good(i))
            ans.push_back(i);

    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << '\n';
}