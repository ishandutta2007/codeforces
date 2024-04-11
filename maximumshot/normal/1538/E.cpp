#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Operation {
    string op = "";
    string var = "";
    string x = "";
    string y = "";
};

const int L = 3;

int occur(string text, string pattern) {
    int res = 0;
    int n = (int) text.size(), m = (int) pattern.size();
    for (int i = 0; i + m - 1 < n; i++) {
        if (text.substr(i, m) == pattern)
            res++;
    }
    return res;
}

ll fast(vector<Operation> ops) {
    int n = (int) ops.size();
    unordered_map<string, string> pref, suff;
    unordered_map<string, ll> dp;
    ll res = 0;
    for (int it = 0; it < n; it++) {
        const auto& o = ops[it];
        string pr, sf;
        if (o.op == ":=") {
            dp[o.var] = occur(o.x, "haha");
            pr = sf = o.x;
        } else {
            dp[o.var] = dp[o.x] + dp[o.y] + occur(suff[o.x] + pref[o.y], "haha");
            pr = pref[o.x]; if ((int) pr.size() < L) pr += pref[o.y];
            sf = suff[o.y]; if ((int) sf.size() < L) sf = suff[o.x] + sf;
        }
        if ((int) pr.size() > L) pr = pr.substr(0, L);
        if ((int) sf.size() > L) sf = sf.substr((int) sf.size() - L, L);
        pref[o.var] = pr;
        suff[o.var] = sf;
        if (it + 1 == n)
            res = dp[o.var];
    }
    return res;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<Operation> ops(n);
        for (auto& operation : ops) {
            string tmp;
            cin >> operation.var >> operation.op;
            if (operation.op == ":=") cin >> operation.x;
            else cin >> operation.x >> tmp >> operation.y;
        }
        ll res = fast(ops);
        cout << res << "\n";
    }

    return 0;
}