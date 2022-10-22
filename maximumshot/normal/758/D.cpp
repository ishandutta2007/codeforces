#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    vec< ll > pw(70);
    pw[0] = 1;
    for(int i = 1;i < 70;i++) {
        pw[i] = pw[i - 1] * ll(n);
    }

    string s;
    cin >> s;

    int sz = (int)s.size();

    vec< int > dp(sz, inf);
    vec< int > from(sz, -1);

    dp[0] = 1;

    for(int i = 1;i < sz;i++) {
        for(int j = i;j >= 0;j--) {
            if(s[j] == '0' && j < i) continue;
            ll value = 0;
            for(int q = j;q <= i && value < n;q++) {
               value = value * 10 + s[q] - '0';
            }
            if(value >= n) break;
            if(dp[i] >= (j ? dp[j - 1] : 0) + 1) {
                dp[i] = (j ? dp[j - 1] : 0) + 1;
                from[i] = j;
            }
        }
    }

//    cout << "\n";
//    for(int i = 0;i < sz;i++) {
//        cout << dp[i] << "" ;
//    }
//    cout << "\n";
//    for(int i = 0;i < sz;i++) {
//        cout << from[i] << "" ;
//    }
//    cout << "\n\n";

    ll result = 0;

    for(int st = 0, i = sz - 1;i >= 0;) {
        int j = max(0, from[i]);
        // j .. i
//        cout << j << " .. " << i << "\n";
        ll value = 0;
        for(int q = j;q <= i;q++) value = value * 10 + s[q] - '0';
        result += value * pw[st++];
        i = j - 1;
    }

    cout << result << "\n";

    return 0;
}