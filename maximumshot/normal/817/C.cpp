#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const L = 30;
int const S = 300;

ll dp[L][S];

void prepare() {
    dp[0][0] = 1;
    for(int l = 1;l < L;l++) {
        for(int s = 0;s < S;s++) {
            for(int x = 0;x < 10 && s + x < S;x++) {
                dp[l][s + x] += dp[l - 1][s];
            }
        }
    }
}

string ll_to_string(ll x) {
    string res = "";
    while(x) {
        res.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(ALL(res));
    return res;
}

ll string_to_ll(string s) {
    ll res = 0;
    for(char d : s) {
        res = res * 10ll + d - '0';
    }
    return res;
}

ll get(ll n, int sm) {
    ll res = 0;
    string s = ll_to_string(n);
    int cur = 0;
    for(int i = 0;i < (int)s.size();i++) {
        for(int x = i == 0;x < s[i] - '0';x++) {
            if(sm >= (cur + x)) {
                res += dp[(int)s.size() - i - 1][sm - (cur + x)];
            }
        }
        cur += s[i] - '0';
    }
    if(cur == sm) res++;

    for(int l = 1;l < (int)s.size();l++) {
        for(int x = 1;x < 10 && x <= sm;x++) {
            res += dp[l - 1][sm - x];
        }
    }

    return res;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    prepare();

    ll n, s;

    cin >> n >> s;

    ll res = 0;

    for(int sm = 1;sm < S && sm + s <= n;sm++) {
        res += get(n, sm);
        if(sm + s > 1) {
            res -= get(sm + s - 1, sm);
        }
    }

    cout << res << "\n";

    return 0;
}