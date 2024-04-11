#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005], pos[300005];
vector <pair <int, int>> ans;

void go(int i, int j) {
    ans.push_back(make_pair(i, j));
    swap(a[i], a[j]);
    pos[a[i]] = i;
    pos[a[j]] = j;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    int k = n / 2;
    for (int i = 1; i <= k; ++i) if (a[i] != i) {
        int j = pos[i];
        if (j <= k) {
            go(i, n);
            go(j, n);
            go(i, n);
        }
        else if (j - i >= k) go(i, j);
        else {
            go(i, n);
            go(j, 1);
            go(1, n);
            go(i, n);
            go(j, 1);
        }
    }
    for (int i = k + 1; i <= n; ++i) if (a[i] != i) {
        int j = pos[i];
        go(i, 1);
        go(j, 1);
        go(i, 1);
    }
    //for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    cout << ans.size() << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second << '\n';
    return 0;
}