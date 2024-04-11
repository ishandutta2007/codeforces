#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
const int64_t INF = 1e18;
char s[nax];
int64_t x, y;
int n;
int64_t ans = INF;

int main() {
    ios::sync_with_stdio(false);
    cin >> s + 1;
    n = strlen(s + 1);
    cin >> x >> y;

    int64_t cur = 0;

    int ct_zero = 0, ct_one = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        char alpha = s[i] == '?' ? '0' : s[i];
        if (alpha == '1') {
            cur += x * ct_zero;
            ct_one += 1;
        } else {
            cur += y * ct_one;
            ct_zero += 1;
        }
    }

    ans = min(ans, cur);
    {
        int left_one = 0;
        int left_zero = 0;
        int one = ct_one;
        int zero = ct_zero;
        int64_t now = cur;

        for (int i = 1 ; i <= n ; ++ i) {
            if (s[i] == '?') {
                    -- zero;
                    now -= y * left_one;
                    now -= x * one;
                    now += x * left_zero;
                    now += y * zero;
                    ++ left_one;
            } else {
                if (s[i] == '1') {
                    -- one;
                    left_one += 1;
                } else {
                    -- zero;
                    left_zero += 1;
                }
            }
            ans = min(ans, now);
        }
    }
    {
        int left_one = 0;
        int left_zero = 0;
        int one = ct_one;
        int zero = ct_zero;
        int64_t now = cur;

        for (int i = n ; i >= 1 ; -- i) {
            if (s[i] == '?') {
                    -- zero;
                    now -= x * left_one;
                    now -= y * one;
                    now += y * left_zero;
                    now += x * zero;
                    ++ left_one;
            } else {
                if (s[i] == '1') {
                    -- one;
                    left_one += 1;
                } else {
                    -- zero;
                    left_zero += 1;
                }
            }
            ans = min(ans, now);
        }
    }

    cout << ans << '\n';
}
/*
    Good Luck
        -Lucina
*/

/**
    ?xxxxxxx?xxxxxxx
    1 a1 b0 0
    0 a1 b0 1
    (b0 + a1) * (10_cost) + 10_cost
    (b0 + a1) * (01_cost) + 01_cost
    Then you can swap 01 or 10 to make the cost cheaper or something
    optimal rearrangement should be 1111100000
    or 00000011111
    calculate it in O(n)
*/