#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m;
vector<vector<int>> a, up;
vector<int> mup;

int main()
{
    cin >> n >> m;
    a = up = vector<vector<int>>(n, vector<int> (m));
    mup = vector<int> (n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int j = 0; j < m; j++)
        up[0][j] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] >= a[i - 1][j])
                up[i][j] = up[i - 1][j] + 1;
            else
                up[i][j] = 0;
    for (int i = 0; i < n; i++)
        mup[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mup[i] = max(mup[i], up[i][j]);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (mup[r] >= r - l)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}