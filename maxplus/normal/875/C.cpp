#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5;

vector<int> a[N], nei[N + 1];

void out() {
    cout << "No\n";
    exit(0);
}

int u[N + 1], big[N + 1], small[N + 1];

void dfs(int i) {
    if (u[i])
        return;
    if (small[i])
        out();
    u[i] = big[i] = 1;
    for (auto j: nei[i])
        if (small[j])
            out();
        else
            dfs(j);
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, l;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> l,
        copy_n(istream_iterator<int>(cin), l, back_inserter(a[i]));
    for (int i = 1; i < n; ++i) {
        int msmtch = -1;
        for (int j = 0; j < min(a[i - 1].size(), a[i].size()); ++j)
            if (a[i - 1][j] != a[i][j]) {
                msmtch = j;
                break;
            }
        if (msmtch != -1)
            if (a[i - 1][msmtch] < a[i][msmtch])
                nei[a[i][msmtch]].push_back(a[i - 1][msmtch]);
            else
                small[a[i][msmtch]] = 1, big[a[i - 1][msmtch]] = 1;
        else if (a[i - 1].size() > a[i].size())
            out();
    }
    for (int i = 1; i <= m; ++i) if (big[i])
        dfs(i);
    cout << "Yes\n";
    cout << accumulate(big + 1, big + m + 1, 0) << '\n';
    for (int i = 1; i <= m; ++i) if (big[i])
        cout << i << ' ';
    return 0;
}