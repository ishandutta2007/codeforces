#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector< int > get_z(const string &s) {
    int n = (int)s.size();
    vector< int > z(n);
    for(int i = 1, l = 0, r = 0;i < n;i++) {
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

vector< int > get_p(const string &s) {
    int n = (int)s.size();
    vector< int > p(n);
    for(int i = 1;i < n;i++) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s, t;

    cin >> s >> t;

    string ts = t + "#" + s;

    ll res = 0;

    vector< int > z = get_z(t);
    vector< int > p((int)ts.size());

    for(int i = 1;i < (int)t.size();i++) {
        int j = p[i - 1];
        while(j > 0 && ts[i] != ts[j]) j = p[j - 1];
        if(ts[i] == ts[j]) j++;
        p[i] = j;
    }

    for(int i = (int)t.size() + 2;i < (int)ts.size();i++) {
        int j = p[i - 1];
        while(j > 0 && ts[i] != ts[j]) j = p[j - 1];
        if(ts[i] == ts[j]) j++;
        p[i] = j;
    }

    for(int i = 0;i < (int)ts.size();i++) {
        int &j = p[i];
        while(j >= (int)t.size()) j = p[j - 1];
    }

    vector< int > dp((int)t.size());

    for(int k = 0;k < (int)t.size();k++) {
        dp[k] = z[k];
        if(k > 0) {
            dp[k] = max(dp[k], dp[ p[k - 1] ]);
        }
    }

    for(int i = 0;i < (int)s.size();i++) {
        int mn = 0;
        int k = p[(int)t.size() + 1 + i];
        if(k > 0)
            mn = dp[k];
//        while(k > 0) {
//            mn = max(mn, z[k]);
//            k = p[k - 1];
//        }
        res += (int)t.size() - mn;
    }

    cout << res << "\n";

    return 0;
}