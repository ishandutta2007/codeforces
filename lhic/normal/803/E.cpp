#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


const int MX = 1200;
int dp[1200][2 * MX];

int n, k;
string s;


int main() {
    cin >> n >> k;
    cin >> s;
    dp[0][MX] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            for (int j = 1; j < 2 * MX; ++j)
                dp[i + 1][j - 1] |= dp[i][j];
        }
        else if (s[i] == 'D') {
            for (int j = 0; j < 2 * MX; ++j)
                dp[i + 1][j] |= dp[i][j];
        }
        else if (s[i] == 'W') {
            for (int j = 0; j < 2 * MX - 1; ++j)
                dp[i + 1][j + 1] |= dp[i][j];
        }
        else {
            for (int j = 0; j < 2 * MX; ++j) {
                if (!dp[i][j])
                    continue;
                if (j > 0)
                    dp[i + 1][j - 1] = 1;
                if (j < 2 * MX - 1)
                    dp[i + 1][j + 1] = 1;
                dp[i + 1][j] = 1;
            }
        }
        if (i != n - 1)
            dp[i + 1][MX + k] = 0, dp[i + 1][MX - k] = 0;
    }
    int now = -1;
    if (dp[n][MX + k])
        now = MX + k;
    else if (dp[n][MX - k]) {
        now = MX - k;
    }
    if (now == -1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L')
            ++now;
        else if (s[i] == 'W')
            --now;
        else if (s[i] == '?') {
            if (dp[i][now])
                s[i] = 'D';
            else if (dp[i][now + 1])
                s[i] = 'L', ++now;
            else if (dp[i][now - 1])
                s[i] = 'W', --now;
        }
    }
    cout << s << "\n";
    return 0;
}