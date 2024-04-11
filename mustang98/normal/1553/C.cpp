#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

string t[4];

int check(string s) {
    int l1 = 5, l2 = 5;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 10; ++i) {
        int pt = (s[i] == '0' ? 0 : 1);
        if (i % 2 == 0) {
            s1 += pt;
            l1--;
        } else {
            s2 += pt;
            l2--;
        }
        if (s1 + l1 < s2 || s2 + l2 < s1) {
            return i + 1;
        }
    }
    return 10;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int ans = inf;
        string t[4];
        for (int i = 0; i < 4; ++i) {
            char c1 = "1001"[i];
            char c2 = "0101"[i];
            t[i] = s;
            for (int j = 0; j < t[i].size(); ++j) {
                if (t[i][j] != '?') continue;
                if (j % 2 == 0) {
                    t[i][j] = c1;
                } else {
                    t[i][j] = c2;
                }
            }
            ans = min(ans, check(t[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}