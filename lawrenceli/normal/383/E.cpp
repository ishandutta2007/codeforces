#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <ios>
#include <cstring>

using namespace std;

const int MAXN = 10100;
const int MAXV = 24;

int n, dp[1<<MAXV], num[1<<MAXV];
string s[MAXN];

int calc(int x) {
    int& ret = dp[x];
    if (ret != -1) return ret;
    ret = num[x];
    if (__builtin_popcount(x) == 1) return ret;
    else if (__builtin_popcount(x) == 2) {
        for (int i=0; i<MAXV; i++)
            if (x & 1<<i)
                ret += calc(x ^ 1<<i);
        return ret;
    } else {
        int a = -1, b = -1;
        for (int i=0; i<MAXV; i++)
            if (x & 1<<i)
                if (a == -1) a = i;
                else if (b == -1) b = i;
                else break;
        ret += calc(x ^ 1<<a) + calc(x ^ 1<<b);
        ret -= calc(x ^ 1<<a ^ 1<<b);
        if (__builtin_popcount(x) > 3)
            for (int i=b+1; i<MAXV; i++)
                if (x & 1<<i)
                    ret += num[1<<a | 1<<b | 1<<i];
        ret += num[1<<a | 1<<b];
        return ret;
    }
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
        set<int> st;
        for (int j=0; j<3; j++) st.insert(s[i][j] - 'a');
        int x = 0;
        for (typeof(st.begin()) it = st.begin(); it != st.end(); it++)
            x += 1<<(*it);
        num[x] ++;
    }

    int ans = 0;
    for (int i=0; i<(1<<MAXV); i++) {
        int res = n - calc(i);
        ans ^= res*res;
    }

    cout << ans << '\n';
    return 0;
}