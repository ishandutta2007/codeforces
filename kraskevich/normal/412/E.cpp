#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define MP make_pair
#define F first
#define S second


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    s = '$' + s;
    int n = s.length();
    long long res = 0;
    vector<ll> let(n, 0);
    vector<ll> dig(n, 0);
    vector<ll> dots(n, 0);
    vector<ll> down(n, 0);
    vector<ll> at(n, 0);
    for (int i = 1; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z')
            let[i]++;
        if ('0' <= s[i] && s[i] <= '9')
            dig[i]++;
        if (s[i] == '@')
            at[i]++;
        if (s[i] == '_')
            down[i]++;
        if (s[i] == '.')
            dots[i]++;
    }
    vector<ll> ndot(n, -1);
    vector<ll> nat(n, -1);
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (at[i] == 1) {
            for (int j = last; j < i; j++)
                nat[j] = i;
            last = i;
        }
    }
    last = 0;
    for (int i = 1; i < n; i++) {
        if (dots[i] == 1) {
            for (int j = last; j < i; j++)
                ndot[j] = i;
            last = i;
        }
    }
    for (int i = 1; i < n; i++) {
        let[i] += let[i - 1];
        dig[i] += dig[i - 1];
        dots[i] += dots[i - 1];
        down[i] += down[i - 1];
        at[i] += at[i - 1];
    }
    for (int i = 1; i < n; i++) {
        if (let[i] - let[i - 1] != 1)
            continue;
        int pat = nat[i];
        if (pat == -1)
            continue;
        int pdot = ndot[i];
        if (pdot == -1 || pdot <= pat + 1)
            continue;
        long long l2 = pdot - pat - 1;
        assert(l2 > 0);
        long long have = dig[pdot - 1] - dig[pat] + let[pdot - 1] - let[pat];
        //cerr << l2 << " " << have << endl;
        if (have != l2)
            continue;
        //cerr << i << endl;
        int l = pdot;
        int r = n - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (m - pdot == let[m] - let[pdot])
                l = m;
            else
                r = m - 1;
        }
        res += l - pdot;
    }
    cout << res;

    return 0;
}