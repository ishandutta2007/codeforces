#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int s[max_n] = {0};

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int t[n + 10][m + 10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) scanf("%d", &t[i][j]);
    }
    int pr[n + 10][m + 10];
    for (int j = 0; j < m; ++j) pr[0][j] = 1;
    s[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j] >= t[i - 1][j]) {
                pr[i][j] = pr[i - 1][j] + 1;
            } else {
                pr[i][j] = 1;
            }
            s[i] = max(s[i], pr[i][j]);
        }
    }
    int q;
    cin >> q;
    int l, r;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        r--;
        l--;
        int cnt = r - l + 1;
        if (s[r] >= cnt) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}