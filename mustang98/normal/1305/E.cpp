#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 5e8 + 100;
const int d = 20000;

int ans[max_n];
int dp[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i < max_n; ++i) {
        dp[i] = dp[i - 2] + i - 2;
    }/*
    for (int i = 3; i < 10; ++i) {
        cout << i << ' ' << dp[i] << endl;
    }*/
    int n, m;
    cin >> n >> m;
    if (m > dp[n]) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i <= n; ++i) {
        if (m == dp[i]) {
            for (int j = 0; j < i; ++j) {
                cout << j + 1 << ' ';
            }
            for (int j = 0; j < n - i; ++j) {
                cout << inf + j * d << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    int lst = 0;
    for (int i = 0; i <= n; ++i) {
        if (m >= dp[i]) {
            lst = i;
        } else {
            break;
        }
    }
    for (int i = 0; i < lst; ++i) {
        cout << i + 1 << ' ';
    }
    int pos = lst;
    for (int val = lst + 1;; ++val) {
        int cur_ans = dp[lst];
        for (int i = 1; i <= lst; ++i) {
            if (val - i > i && val - i <= lst) {
                ++cur_ans;
            }
        }
        if (cur_ans == m) {
            cout << val << ' ';
            for (int i = lst + 2; i <= n; ++i) {
                cout << inf + (i - lst - 2) * d << ' ';
            }
            cout << endl;
            return 0;
        }
        if (cur_ans < m) {
            exit(228);
        }
    }


    return 0;
}