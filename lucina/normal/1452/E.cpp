#include<bits/stdc++.h>
using namespace std;
int const nax = 2048;
int l[nax];
int r[nax];
int n, m, k;
int ans;
int sc[nax + nax];

void add_event(int x, int y) {
    sc[x + nax] += y;
}

int get(int x) {
    return sc[x + nax];
}

int calc(int p, int l, int r) {
    return max(0, min(r, p + k - 1) - max(p, l) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> l[i] >> r[i];
        -- l[i];
        -- r[i];
    }


    for (int first = 0 ; first + k - 1 < n ; ++ first) {
        int cur = 0;

        memset(sc, 0, sizeof(sc));

        for (int i = 1 ; i <= m ; ++ i) {
            int foo = calc(first, l[i], r[i]);
            int len = r[i] - l[i] + 1;
            cur += foo;
            /// treating thing start at -k and much easier life.

            if (k <= len) {
                add_event(l[i] + 1 + foo - k, 1);
                add_event(l[i] + 1, -1); /// increasing till ?
                add_event(r[i] - k + 2, -1);
                add_event(r[i] - foo + 2, 1); /// decreasing till ?
                /// keep decreasing exactly len - foo
            } else {
                /// l[i]
                add_event(l[i] + 1 + foo - k, 1);
                add_event(r[i] - k + 2, -1); /// increasing till ?
                add_event(l[i] + 1, -1);
                add_event(r[i] - foo + 2, 1); /// decreasing till ?
            }
            /// this should be simple to calculate why is it so painful?
        }

            /// 0-index is easier in this case.
        int carry = 0;
        for (int i = -k, j = 0 ; i + k - 1 < n ; ++ i) {
            carry += get(i);
            cur += carry;
            ans = max(ans, cur);
        }


    }

    cout << ans << '\n';
}


/**
1 -1
1 -1
1 -1
1 1
1 1
1 1
1 1
2 -1
2 -1
3 1
3 1
3 1
6 -1
6 -1
6 -1
6 1
7 -1
7 -1
10 1
10 1

*/