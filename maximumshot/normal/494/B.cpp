#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

#define mp make_pair
#define vec vector
#define ALL(x) (x).begin(), (x).end() 

typedef long long ll;
typedef long double ld;

const ll inf = 1000000000ll;
const ll mod = inf + 7ll;

const int N = 100100;

void read(string & s) {
    char buff[N];
    scanf("%s", &buff);
    s = buff;
}

void add(ll & x, ll y) {
    x = (x + y) % mod;
}

bool solve() {
    
    string s, t;

    read(s);
    read(t);

    int n, m;
    n = (int)s.size();
    m = (int)t.size();

    string a = t + "#" + s;

    vec< int > p(a.size());

    for(int i = 1;i < (int)p.size();i++) {
        int j = p[i - 1];
        while(j > 0 && a[j] != a[i]) j = p[j - 1];
        if(a[j] == a[i]) j++;
        p[i] = j;
    }

    vec< char > can(n);
    vec< int > last(n, -1);

    for(int i = 0;i < n;i++) {
        if(p[i + m + 1] == m) can[i] = 1;
    }

    for(int i = 0;i < n;i++) {
        if(i > 0) last[i] = last[i - 1];
        if(can[i]) last[i] = i;
    } 

    vec< ll > dp(n), sumdp1(n), sumdp2(n);
    ll ans = 0;

    for(int i = 0;i < n;i++) {
        int q = last[i];    
        add(dp[i], max(q - m + 2, 0));
        add(dp[i], q - m >= 0?sumdp1[q - m] * ll(q - m + 1) % mod : 0);
        add(dp[i], q - m >= 0?-sumdp2[q - m] : 0);
        dp[i] = (dp[i] % mod + mod) % mod;
        add(sumdp1[i], (i > 0?sumdp1[i - 1] : 0) + dp[i]);
        add(sumdp2[i], (i > 0?sumdp2[i - 1] : 0) + ll(i) * dp[i] % mod);
        add(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}

int main() {
    
    //while(solve());
    solve();

    return 0;
}