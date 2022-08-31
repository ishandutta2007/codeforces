#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 255, max_len = 100111, inf = 1000111222;

int dp[max_n][max_n][max_n];

string b;
string s[3];
int nxt[30][max_len];

void calc_nxt() {
    for (char c = 'a'; c <= 'z'; ++c) {
        int ci = c - 'a';
        int lst = inf;
        for (int i = b.size(); i >= 0; --i) {
            if (i < b.size() && b[i] == c) {
                lst = i;
            }
            nxt[ci][i] = lst;
        }
    }
}

void calc() {
    dp[0][0][0] = 0;
    for (int i = 0; i <= s[0].size(); ++i) {
        for (int j = 0; j <= s[1].size(); ++j) {
            for (int k = 0; k <= s[2].size(); ++k) {
                if (i) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[0][i - 1] - 'a'][dp[i - 1][j][k]] + 1);
                }
                if (j) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[1][j - 1] - 'a'][dp[i][j - 1][k]] + 1);
                }
                if (k) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[2][k - 1] - 'a'][dp[i][j][k - 1]] + 1);
                }
            }
        }
    }
}

void update(int rel) {
    //cout << rel << endl;
    if (rel == 0) {
        for (int j = 0; j <= s[1].size(); ++j) {
            for (int k = 0; k <= s[2].size(); ++k) {
                dp[s[0].size()][j][k] = inf;
            }
        }
        for (int j = 0; j <= s[1].size(); ++j) {
            for (int k = 0; k <= s[2].size(); ++k) {
                int i = s[0].size();
                if (i && dp[i - 1][j][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[0][i - 1] - 'a'][dp[i - 1][j][k]] + 1);
                }
                if (j && dp[i][j - 1][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[1][j - 1] - 'a'][dp[i][j - 1][k]] + 1);
                }
                if (k && dp[i][j][k - 1] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[2][k - 1] - 'a'][dp[i][j][k - 1]] + 1);
                }
            }
        }
    }
    if (rel == 1) {
        for (int i = 0; i <= s[0].size(); ++i) {
            for (int k = 0; k <= s[2].size(); ++k) {
                dp[i][s[1].size()][k] = inf;
            }
        }
        for (int i = 0; i <= s[0].size(); ++i) {
            for (int k = 0; k <= s[2].size(); ++k) {
                int j = s[1].size();
                if (i && dp[i - 1][j][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[0][i - 1] - 'a'][dp[i - 1][j][k]] + 1);
                }
                if (j && dp[i][j - 1][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[1][j - 1] - 'a'][dp[i][j - 1][k]] + 1);
                }
                if (k && dp[i][j][k - 1] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[2][k - 1] - 'a'][dp[i][j][k - 1]] + 1);
                }
            }
        }
    }
    if (rel == 2) {
        for (int i = 0; i <= s[0].size(); ++i) {
            for (int j = 0; j <= s[1].size(); ++j) {
                dp[i][j][s[2].size()] = inf;
            }
        }
        for (int i = 0; i <= s[0].size(); ++i) {
            for (int j = 0; j <= s[1].size(); ++j) {
                int k = s[2].size();
                if (i && dp[i - 1][j][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[0][i - 1] - 'a'][dp[i - 1][j][k]] + 1);
                }
                if (j && dp[i][j - 1][k] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[1][j - 1] - 'a'][dp[i][j - 1][k]] + 1);
                }
                if (k && dp[i][j][k - 1] != inf) {
                    dp[i][j][k] = min(dp[i][j][k], nxt[s[2][k - 1] - 'a'][dp[i][j][k - 1]] + 1);
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_n; ++j) {
            for (int k = 0; k < max_n; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    int n, q;
    cin >> n >> q;
    cin >> b;
    calc_nxt();
    for (int i = 0; i < q; ++i) {
        char t, l;
        int rel;
        cin >> t >> rel;
        --rel;
        if (t == '-') {
            s[rel].pop_back();
        } else {
            cin >> l;
            s[rel] += l;
            update(rel);
        }
        if (dp[s[0].size()][s[1].size()][s[2].size()] != inf) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}